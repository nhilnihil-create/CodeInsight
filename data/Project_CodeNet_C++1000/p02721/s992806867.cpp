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
#define debug(x) cerr <<__LINE__<< ": " << #x << " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> L, R;
    rep(i, n) {
        if (s[i] == 'o') L.push_back(i + 1), i += c;
        if ((int)L.size() == k) break;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'o') R.push_back(i + 1), i -= c;
        if ((int)R.size() == k) break;
    }
    reverse(all(R));
    rep(i, k) if (L[i] == R[i]) cout << L[i] << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
