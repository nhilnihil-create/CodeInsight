#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
 
#define mx(ans, cnt) ans = max(ans, cnt)
#define fauto(a) for(auto i : a) cout << i << " "; cout << endl;
#define sp(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define _ << " " <<
#define swp(x, y) if (x > y) swap(x, y);
#define swpg(x, y) if (x < y) swap(x, y);
#define ff first
#define ss second
#define xx first
#define yy second
#define pb push_back
#define nn end1
 
 
using ll = long long;
using ull = unsigned long long;
using namespace std;
int main ()
{
    ll n,i,j,c=0;
    vector<ll> v;
    cin>>n;
    for(i=0;i<n-1;i++)
    {ll q; cin>>q; v.pb(q);}
    if(n==2)
    {cout<<2*v[0]<<endl;}
    else
    {
        c=c+v[0];
        c=c+v[n-2];
        for(i=0;i<n-2;i++)
        {c=c+min(v[i+1],v[i]);}
        cout<<c<<endl;
    }
    return 0;
}