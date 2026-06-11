#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007
#define PI 3.14159265359
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     char  x,y,z;
     char a,b,c;
     cin>>x>>y>>z>>a>>b>>c;
     int ct=0;
     if(x==a)
     ct++;
     if(y==b)
     ct++;
     if(z==c)
     ct++;
     cout<<ct<<endl;
	 
    return 0;
}
