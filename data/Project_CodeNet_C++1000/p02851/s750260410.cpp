#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

using ll = long long;

int main() {
    int n, k; cin >> n >> k;
    map<int, int> memo;

    ll s = 0;
    ll ans = 0;
    vector<ll> ls;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        --a;
        s += a;
        ls.push_back(s);
        if (s%k == 0 && i < k-1) ans += 1;
        if (i >= k) {
            --memo[ls[i-k]%k];
        }
        ans += memo[s%k];
        ++memo[s%k];
        // cerr << a << " " << s << " " << s%k << " " << memo[s%k] << endl;
    }
    cout << ans << endl;
}
