#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n,k; cin >> n >> k;
    int h[n]; rep(i,n) cin >> h[i];
    int ans = 0;
    rep(i,n) {
        if (h[i] >= k) ans++;
    }
    cout << ans << endl;
    
    return 0;
}
