#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> P;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
const int MAXN = 100000;
const int MAXE = 100000;
const int MAXV = 10000;
const int inf = 1e9;
const ll INF = 2e18;
const ll MOD = 1e9 + 7;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[ry]>rank[rx]) par[rx]=ry;
        else par[ry]=rx;
        if(rank[rx]==rank[ry]) rank[rx]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
};

vector<ll> fac,inv,finv;

void initcom(){
    fac=inv=finv=vector<ll>(1e6);
    fac[0]=fac[1]=1;
    inv[1]=1;
    finv[0]=finv[1]=1;
    for(ll i=2;i<1e6;++i){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll com(int n,int k){
    if(n<0||k<0) return 0;
    if(n<k) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll x,ll y){
    if(y==0) return x;
    return gcd(y,x%y);
}
ll mopow(ll a,ll x,ll mod){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}
int main(){
    int n;cin>>n;
    vector<int> d(n),cnt(n,0);
    for(int i=0;i<n;++i){
        cin>>d[i];
        cnt[d[i]]++;
    }
    bool flag=true;
    if(d[0]!=0) flag=false;
    if(cnt[0]!=1) flag=false;
    for(int i=1;i<n;++i){
        if(cnt[i-1]==0&&cnt[i]>0) flag=false;
    }
    if(!flag){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    ll mod=998244353;
    for(int i=0;i<n-1;++i){
        if(cnt[i]==0) break;
        ans=ans*mopow(cnt[i],cnt[i+1],mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}