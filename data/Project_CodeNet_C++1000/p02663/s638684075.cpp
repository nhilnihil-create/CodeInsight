#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define pb(x) push_back(x)
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(),v.end()
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int32_t main()
{
int h1,h2,m1,m2,k;
cin>>h1>>m1>>h2>>m2>>k;
int p=(h1*60)+m1;
int q=(h2*60)+m2;
int ans=q-p-k;
cout<<ans;
}
