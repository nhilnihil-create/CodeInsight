#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

const int BIG_NUM = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    ll ans = 1;
    rep(i, n) {
        if(a[i] == 0) {
            cout << 0 << "\n";
            return 0;
        }
    }
    rep(i, n) {
        if(a[i] <=  1000000000000000000 / ans) {
            ans *= a[i];
        } else {
            ans = -1;
            break;
        }
    }
    cout << ans;
    return 0;
}
