#include<iostream>
//#include <cmath>
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
#define FOR(i,a,n) for(ll i=(a);i<(n);++i)
#define ROF(i,a,n) for(int i=(a);i>(n);--i)

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 //   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    ll k;cin>>k;
    ll n=0;ll f;
    FOR(i,0,k){
        n=10*n+7;
        n=n%k;
        if(n==0){
            cout<<i+1;
            return 0;
        }
    }
   // cout<<f;
    cout<<-1;
    return 0;
}