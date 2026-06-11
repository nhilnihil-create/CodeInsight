#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<ll>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vecpll vector<pll>
#define vecbl vector<bool>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
string stin(){string s;cin>>s;return s;}

ll mod=1000000007;
vecll perm;

ll modpow(ll a,ll b){
    if(b==0)return 1;
    if(b%2==0){
        ll d=modpow(a,b/2);
        return d*d%mod;
    }
    return a*modpow(a,b-1)%mod;
}

ll divide(ll a,ll b){
    return a*modpow(b,mod-2)%mod;
}

void makeperm(vecll v, ll size){
    v.resize(size);
    v[0]=1;
    rep(i,size-1)v[i+1]=v[i]*(i+1)%mod;
}

ll comb(ll a,ll b){
    return divide(divide(perm[a],perm[b]),perm[a-b]);
}

int main(){
    int n=in(),k=in();
    makeperm(perm,n+3);
    vecll cnt(k+1);
    cnt[k]=1;
    ll ans=0;
    rep3(i,k-1,1){
        cnt[i]=modpow(k/i,n);
        ll tmp=i*2;
        while(tmp<=k){
            cnt[i]-=cnt[tmp];
            tmp+=i;
        }
    }
    rep(i,k){
        ans+=cnt[i+1]*(i+1)%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}