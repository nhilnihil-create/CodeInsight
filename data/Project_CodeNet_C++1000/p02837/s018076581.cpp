#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> p[n];
    rep(i,n) {
        int a; cin >> a;
        rep(j,a) {
            int x,y; cin >> x >> y;
            p[i].push_back({x-1,y});
        }
    }
    int ans = 0;
    rep(i,1<<n) {
        int b[n];
        rep(j,n) {
            if (i&(1<<j)) {
                b[j] = 1;
            } else {
                b[j] = 0;
            }
        }
        bool flag = 1;
        rep(j,n) {
            if (i&(1<<j)) {
                for (auto pp : p[j]) {
                    if (b[pp.first] != pp.second) {
                        flag = 0;
                    }
                }
            }
        }
        if (!flag) continue;
        int anss = 0;
        rep(j,n) {
            if (i&(1<<j)) anss++;
        }
        ans = max(ans,anss);
    }
    cout << ans << endl;
    return 0;
}
