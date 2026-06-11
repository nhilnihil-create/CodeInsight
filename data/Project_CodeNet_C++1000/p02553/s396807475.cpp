#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int a,b,c,d;
 cin>>a>>b>>c>>d;
 long long int  maxi;
 long long int  maxi1,maxi2;
 maxi1=max(a*c,a*d);
 maxi2=max(b*c,b*d);
 maxi=max(maxi1,maxi2);
 cout<<maxi;
}