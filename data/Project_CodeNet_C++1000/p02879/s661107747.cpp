#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
#define ld long double
#define ff first
#define ss second
using namespace std;

ll fact(ll a)
{
    if(a==0) return 1;
    else return a*fact(a-1);
}

int main()
{
    ll i,j,n,k,t,m,a,b;
    cin>>a>>b;
    if(a>9 || b>9) cout<<"-1";
    else cout<<a*b;
}