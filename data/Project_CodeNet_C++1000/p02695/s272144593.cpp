#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr <<__LINE__<< ": " << #x << " -> " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" -> ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int n, m, q;
int ans;
int A[60], B[60], C[60], D[60];

int calc(vector<int> &X) {
    int ret = 0;
    rep(i, q) {
        if (X[B[i]] - X[A[i]] == C[i]) ret += D[i];
    }
    return ret;
}

void dfs(vector<int> X) {
    if (X.size() == n) {
        chmax(ans, calc(X));
        return;
    }
    int a = 1;
    if (!X.empty()) a = X.back();

    REP(i, a, m + 1) {
        auto vec = X;
        vec.push_back(i);
        dfs(vec);
    }
    return;
}

void solve() {
    cin >> n >> m >> q;
    rep(i, q) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--; B[i]--;
    }
    vector<int> Z;
    dfs(Z);
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
