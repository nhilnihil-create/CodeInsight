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


int main() {
    int n,m; cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    rep(i,m) cin >> p[i] >> s[i];
    rep(i,m) p[i]--;
    vector<int> wa(n);
    vector<bool> flag(n); //acしたらtrue
    rep(i,m) {
        if (flag[p[i]] == true) continue;
        if (s[i] == "AC") {
            flag[p[i]] = true;
        }
        else wa[p[i]]++;
    }
    int cntac = 0;
    int cntwa = 0;
    rep(i,n) {
        if (flag[i] == false) { //acできてないなら
            continue;
        }
        cntac++;
        cntwa += wa[i];
    }
    cout << cntac << " " << cntwa << endl;
}