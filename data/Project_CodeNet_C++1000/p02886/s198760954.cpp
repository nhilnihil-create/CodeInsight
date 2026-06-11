#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
int INF = 1001001001;

int main() {
    int n; cin >> n;
    int d[n]; rep(i,n) cin >> d[i];
    int ans = 0, now = 0;
    rep(i,n) {
        ans += d[i]*now;
        now += d[i];
    }
    cout << ans << endl;
    return 0;
}
