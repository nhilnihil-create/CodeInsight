#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1e9+7
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;

int fact(int n) {
    if (n == 0) return 1;
    else return n*fact(n-1);
}

int main() {
    int n; cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) {
        cin >> p[i];
    }
    rep(i,n) {
        cin >> q[i];
    }
    vector<int> a(n);
    rep(i,n) a[i] = i+1;

    map<vector<int>, int> mp;
    do {
      mp[a] = mp.size();
    } while (next_permutation(all(a))); //next_permutation...aを辞書順で次のものに置き換える

    int ans = abs(mp[p] - mp[q]);
    cout << ans << endl;
}