#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/dsu>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 100100100100100;

int main() {
    int n; cin >> n;
    ll k; cin >> k;
    vector<int> a(n); rep(i,n) cin >> a[i];
    vector<int> f(n); rep(i,n) cin >> f[i];
    sort(all(a));
    sort(all(f),greater<>());
    ll ng = -1;
    ll ok = INF;
    ll mid;
    while (ok-ng > 1) {
        mid = (ok+ng)/2;
        ll cnt = 0;
        rep(i,n) {
            cnt += max(a[i]-mid/f[i], 0ll);
        }
        if (cnt <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    //rep(i,n) {printf("%d ", a[i]);} printf("\n");
    //rep(i,n) {printf("%d ", f[i]);} printf("\n");
    return 0;
}