#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)cin >> a[i];

    if(k == 0){
        int ans = 0;
        rep(i, n)ans = max(ans, a[i]);
        cout << ans << endl;
        return 0;
    }

    int l = 0;
    int r = 1001001001;
    while(l + 1 < r){
        int x = (l + r) / 2;
        ll cnt = 0;
        rep(i, n){
            if(a[i] % x == 0)cnt += a[i] / x - 1;
            else cnt += a[i] / x;
        }
        if(cnt <= k)r = x;
        else l = x;
    }

    cout << r << endl;
}