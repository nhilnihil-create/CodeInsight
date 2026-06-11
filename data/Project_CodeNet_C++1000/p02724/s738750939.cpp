#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   ll x;
   cin>>x;
   ll t=x/500;
   ll r=x%500;
   ll y=r/5;
   cout<<t*1000+y*5<<"\n";
}
