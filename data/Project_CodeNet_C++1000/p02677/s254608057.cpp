 #include <bits/stdc++.h>

#include<stdlib.h>
#include<iostream>
#include<math.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define INF 2000000000
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define PI 3.1415926535897932
using namespace std;

int main()
{
IOS;
double a,b,h,m;
cin>>a>>b>>h>>m;
double ans;
double a1=(30*h)+m/2;
double a2=(6*m);
double angle=abs(a1-a2)*PI/180;
ans=sqrt(a*a+b*b-2*a*b*cos(angle));
cout<<std::setprecision(15)<<ans;




return 0;
}