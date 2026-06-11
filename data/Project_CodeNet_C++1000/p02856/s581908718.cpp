#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int M;
ll d_sum, c_sum;

int main() {
    cin >> M;
    d_sum = c_sum = 0;
    rep(i, M) {
        ll d, c;
        cin >> d >> c;
        c_sum += c;
        d_sum += d * c;
    }
    ll ans = c_sum - 1 + (d_sum - 1) / 9;
    cout << ans << endl;
}
