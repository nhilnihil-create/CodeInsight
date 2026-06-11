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
#include <numeric>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecvec vector<vec>
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

const ll mod = 1000000007;
int n,k;
vec par,num;
vector<vec> chi;
vecll P;

void makeChi(int x){
    if(x!=0)num[x]--;
    REP(e,chi[x])if(e!=par[x]){
        par[e]=x;
        makeChi(e);
    }
    return;
}

void makePerm(int m){
    P.resize(m);
    P[0]=1;
    rep(i,m-1){
        P[i+1]=P[i]*(i+1)%mod;
    }
    return;
}

ll modpow(ll a,ll b){
    if(b==0)return 1;
    if(b%2==0){
        ll d=modpow(a,b/2);
        return d*d%mod;
    }
    return modpow(a,b-1)*a%mod;
}

ll di(ll a,ll b){
    return a*modpow(b,mod-2)%mod;
}

ll Perm(ll a,ll b){
    if(a<b)return 0;
    return di(P[a],P[a-b]);
}

ll func(int x){
    ll res=x==0?Perm(k,num[0]+1):Perm(k-2,num[x]);
    REP(e,chi[x])if(e!=par[x]){
        res = res*func(e)%mod;
    }
    return res;
}

int main(){
    n=in();
    k=in();
    par.resize(n);
    num.resize(n);
    chi.resize(n);
    rep(i,n-1){
        int a=in()-1,b=in()-1;
        chi[a].pb(b);
        chi[b].pb(a);
        num[a]++;
        num[b]++;
    }
    makePerm(max(n,k)+1);
    par[0]=-1;
    makeChi(0);
    cout<<func(0)<<endl;
}
