#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

const int MAX = 1000010;
// const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    COMinit();
    int N,K;cin>>N>>K;
    vector<vector<int>> tree(N,vector<int>());
    rep(i,N-1) {
        int a,b;cin>>a>>b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> par(N,-1);
    ll ans = 1;
    queue<int> qu;
    qu.push(0);
    ans *= K;
    vector<bool> done(N,false);
    done[0] = true;
    while(!qu.empty()) {
        int now = qu.front();
        qu.pop();
        int cnt = 0;
        for(auto nxt : tree[now]) {
            if(!done[nxt]) {
                cnt++;
                ans = (ans * cnt) % MOD;
                done[nxt] = true;
                qu.push(nxt);
                par[nxt] = now;
            }
        }
        if(par[now]==-1) {
            ans = (ans * COM(K-1,cnt))%MOD;
        } else {
            ans = (ans * COM(K-2,cnt))%MOD;
        }
    }
    cout<<ans<<endl;
}