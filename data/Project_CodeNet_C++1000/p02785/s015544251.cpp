#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    sort(h.begin(), h.end());
    ll ans = 0;
    rep(i,n-k) ans += h[i];
    cout << ans << endl;

    return 0;
}
