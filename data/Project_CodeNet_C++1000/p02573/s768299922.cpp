#include <bits/stdc++.h>

using namespace std;
 
//#define int long long
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define reps(i,n) for(ll i=0;i<=n;i++)

ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
 
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct UnionFind{
    vector<ll> par;
    vector<ll> siz;

    UnionFind(ll N):par(N),siz(N,1){
        for(int i = 0;i<N;i++){
            par[i] = i;
        }
    }

    ll root(ll x){
        if(par[x]==x)
        return x;
        return par[x]=root(par[x]);
    }

    void unite(ll x, ll y){ //xとyを結合
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(siz[x]<siz[y])swap(x,y);
        siz[x]+=siz[y];
        par[y]=x;
    }

    ll size(ll x){
        return siz[root(x)];
    }

    bool same(ll x,ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    ll N,M,ans=0;
    ll x,y;
    cin >> N >> M;

    UnionFind rel(N);

    for(ll i=0;i<M;i++){
        cin >> x >> y; 
        rel.unite(x-1,y-1);
    }

    for(ll i=0;i<N;i++){
        ans = max(ans,rel.size(i));
    }

    cout << ans << endl;

    return 0;
}
