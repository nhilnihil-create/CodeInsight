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
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> x(n),y(n);
    rep(i,n) {
        cin >> a[i];
        rep(j,a[i]) {
            int a,b;
            cin >> a >> b;
            x[i].push_back(a);
            y[i].push_back(b);
        }
    }
    int ans = 0;
    rep(i,1<<n) { //正直者のbitを立てる
        bool check = true;
        rep(j,n) {
            if (i & 1<<j) { //j番目の人が正直者と仮定されている場合
                rep(k,a[j]) { //j番目の人の証言を精査
                    if (!(((i >> (x[j][k]-1)) & 1) ^ y[j][k])) continue;
                    else {
                        check = false;
                        break;
                    }
                }
            }
            if (!check) break;
        }
        if (check) { //正直者の証言が全て正しければ
            int s = __builtin_popcount(i);
            chmax(ans,s);
        }
    }
    cout << ans << endl;
}   