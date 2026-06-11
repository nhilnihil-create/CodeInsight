#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define debug(x) cerr <<__LINE__<< ": " <<#x<< " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int n;

void solve() {
    cin >> n;
    vector<int> X, P(8), Q(8);
    int a, b;
    REP(i, 1, n + 1) X.emplace_back(i);
    rep(i, n) cin >> P[i];
    rep(i, n) cin >> Q[i];
    auto check = [](vector<int> a, vector<int> b) {
        rep(i, n) if (a[i] != b[i]) return 0;
        return 1;
    };
    int cnt = 0;
    do {
        if (check(X, P)) a = cnt;
        if (check(X, Q)) b = cnt;
        cnt++;
    } while(next_permutation(all(X)));
    cout << abs(a - b) << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
