#include <iostream>
#include <vector>

using namespace std;

using ll =  long long;

constexpr int K_MAX = 5000;

int k;
vector<ll> d(K_MAX);

void solve() {
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> dd(d);
    for(int i=0;i<k;++i) {
        dd[i] %= m;
    }

    ll dd_cnt, x_sum = x % m, zero = 0;
    for(int i=0;i<k;++i) {
        dd_cnt = (n-1 - (i+1) + k) / k;
        if(dd[i]) {
            x_sum += dd[i] * dd_cnt;
        } else {
            zero += dd_cnt;
        }
    }

    cout << n - 1 - x_sum/m - zero << endl;
}

int main() {
    int q;
    cin >> k >> q;
    for(int i=0;i<k;++i) cin >> d[i];
    while(q--) {
        solve();
    }
}
