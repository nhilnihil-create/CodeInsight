/*
17/10/2017
*/
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll n,a,b;
cin>>n>>a>>b;
ll k=n/(a+b);
n%=(a+b);
cout<<k*a+min(n,a)<<endl;
}

