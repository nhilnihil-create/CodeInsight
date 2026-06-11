#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
const int INF = 1e18;

const int M_battle = 1000* 999 /2 + 100;

int d[M_battle], longest_path;
vector<int> G[M_battle];
int ans;
int seen[M_battle];

int dfs(int k){
    if(seen[k] == 2) return d[k];
    seen[k] = 1;
    for(auto e: G[k]){
        if(seen[e] == 1){
            cout << -1 << endl;
            exit(0);
        }
        chmax(d[k],dfs(e)+1);
    }
    seen[k] = 2;
    return d[k];
}

signed main(){
    int n; cin >> n;
    const int bat = n*(n-1)/2;
    REP(i,n){
        int a[n-1];
        REP(j,n-1){
            cin >> a[j];
            a[j]--;
        }
        REP(j,n-2){
            int x = i, y = a[j], z = i, w = a[j+1];
            if(y > x)swap(x,y);
            if(w > z)swap(z,w);
            int now = x - y + (n*2 -y -1) * y / 2;
            int next = z - w + (n*2 -w -1) * w / 2;
            if(!j)G[0].pb(now);
            G[now].pb(next);
        }
    }
    cout << dfs(0) << endl;
}