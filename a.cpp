#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;

char c[30];
int n;
ofstream f("a.txt");
void afiseaza();
int verifica(int );
void generare(int i)
{
    char j;
    if(i>n)
        afiseaza();
    else
        for(j='a';j<='z';j++)
        {
            c[i]=j;
            if(verifica(i))
                generare(i+1);
        }
}
int verifica(int k)
{
    int i;
    if(strchr("aeiou",c[1])!=NULL)
        return 0;
    /*
    if(strchr("aeiou",c[k])==NULL)
        return 0;
    */
    for(i=1;i<=k-2;i++)
        if((strchr("aeiou",c[i])==NULL)&&(strchr("aeiou",c[i+1])==NULL)&&(strchr("aeiou",c[i+2])==NULL))
            return 0;
    return 1;
}
void afiseaza()
{
    int i;
    for(i=1;i<=n;i++)
        f<<c[i]<<" ";
    f<<"\n";
}
int main()
{
    cout<<"n=";
    cin>>n;
    generare(1);
    f.close();
    return 0;
}
