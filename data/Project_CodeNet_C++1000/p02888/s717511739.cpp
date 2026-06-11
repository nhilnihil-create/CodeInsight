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
    vector<int> a(n); rep(i,n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    rep(i,n) {
        rep(j,i) {
            int l = a[i]+a[j];
            auto it = lower_bound(all(a), l);
            int c = it-a.begin();
            ans += c-i-1;
            //printf("%d %d %d\n", a[j], a[i], l);
        }
    }
    cout << ans << endl;
    return 0;
}
