/**Bismillahir Rahmanir Rahim.**/
/*gcd=--gcd(a,b);*/
/*double p =log(a);
    p=p-floor(p);
    int x=pow(10,p);    m s di
 int x =floor(log10(a)) + 1;  d co
 a=ceil(log2(n)) == floor(log2(n)); pow of 2*/

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
#define nl endl
#define in cin
#define out cout
#define ll long long
int main()
{
    long long int a,b,c,d=0,i,x,y=0,j,n,xx;
    char s[1000000];
    in>>a>>b>>c;
    for(i=a;i<=b;i++)
    {
        if(i%c==0)
        {
            y++;
        }
    }
    out<<y<<nl;


}
