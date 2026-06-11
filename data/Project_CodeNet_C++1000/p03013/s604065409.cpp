#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),memo(n+10);
    rep(i,m){
        int b;
        cin>>b;
        a[b]=1;
    }
    memo[0]=1;
    if(a[1]==0){
        memo[1]=1;
    }
    for(ll i=2;i<=n+3;i++){
        if(a[i]==1) continue;
        memo[i]=memo[i-1]+memo[i-2];
        memo[i]%=1000000007;
    }
    cout<<memo[n];
}