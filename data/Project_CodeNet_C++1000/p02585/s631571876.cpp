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
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> P;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
const int MAXN = 100000;
const int MAXE = 100000;
const int MAXV = 10000;
const int inf = 1e9;
const ll INF = 2e18;
const ll MOD = 1e9 + 7;

struct UnionFind
{
    vector<int> par, rank;
    UnionFind(int n) : par(n), rank(n)
    {
        for (int i = 0; i < n; ++i)
            par[i] = i;
    }
    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return;
        if (rank[ry] > rank[rx])
            par[rx] = ry;
        else
            par[ry] = rx;
        if (rank[rx] == rank[ry])
            rank[rx]++;
    }
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
};

vector<ll> fac, inv, finv;

void initcom()
{
    fac = inv = finv = vector<ll>(1e6);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (ll i = 2; i < 1e6; ++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll com(int n, int k)
{
    if (n < 0 || k < 0)
        return 0;
    if (n < k)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
ll mopow(ll a, ll x, ll mod)
{
    ll res = 1;
    while (x > 0)
    {
        if (x & 1)
            res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

int main(){
    int n,k;cin>>n>>k;
    vector<int> p(n),c(n);
    for(int i=0;i<n;++i) cin>>p[i],--p[i];
    for(int i=0;i<n;++i) cin>>c[i];
    ll ans=-INF;
    vector<bool> used(n,false);
    vector<vector<ll> > ss;
    for(int i=0;i<n;++i){
        if(used[i]) continue;
        int cur=i;
        vector<ll> s;
        while(!used[cur]){
            used[cur]=true;
            s.push_back(c[cur]);
            cur=p[cur];
        }
        ss.push_back(s);
    }
    for(auto vec:ss){
        ll m=vec.size();
        vector<ll> sum(2*m+1,0);
        for(int i=0;i<2*m;++i) sum[i+1]=sum[i]+vec[i%m];
        
        vector<ll> rem(m,-INF);
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                rem[j]=max(rem[j],sum[i+j]-sum[i]);
            }
        }

        for(int r=0;r<m;++r){
            if(r>k) continue;
            ll q=(k-r)/m;
            if(r==0&&q==0) continue;

            if(sum[m]>0) ans=max(ans,rem[r]+sum[m]*q);
            else if(r>0) ans=max(ans,rem[r]);
        }
    }
    cout<<ans<<endl;
    return 0;
}