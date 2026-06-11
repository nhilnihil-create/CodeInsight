#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <numeric>
#include <queue>
#define mod 1000000007
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define srep(i,s,t) for (ll i = s; i < t; i++)
#define drep(i,n) for(ll i = (n)-1; i >= 1; i--)
using namespace std;
typedef long long ll;
typedef vector<vector<char>> field_t;
typedef unsigned long long ull;
typedef pair<ll, ll> point_t;
ll modpow(ll k,ll n){
    ll x=1;
    while(n>0){
        if(n&1)x=x*k%mod;
        k=k*k%mod;
        n>>=1;
    }
    
    return x;
}

int main()
{
    
    ll N,ans,cnt,K;
    ans=0;
    cnt=0;
    cin >> N >>K;
    ll num[K+1]={};
    for(ll i=K;i>=1;i--){
        num[i]+=modpow((K/i),N);
        num[i]%=mod;
        ans+=(num[i]*i)%mod;
        ans%=mod;
        for(ll j=1;j*j<=i;j++){
            if(i%j==0){
                num[j] += mod - num[i];
                if(j!=1 && j*j!=i) num[i/j] += mod - num[i];
                num[j] %= mod;
                num[j/i] %= mod;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}