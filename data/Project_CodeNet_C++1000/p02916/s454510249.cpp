#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n; cin >> n;
    int a[n]; rep(i,n) cin >> a[i];
    int b[n]; rep(i,n) cin >> b[i];
    int c[n-1]; rep(i,n-1) cin >> c[i];
    int ans = b[a[0]-1];
    rep(i,n-1) {
        ans += b[a[i+1]-1];
        if (a[i]+1 == a[i+1]) {
            ans += c[a[i]-1];
        }
    }
    cout << ans << endl;
    return 0;
}
