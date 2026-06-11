#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    const ll mod = 1000000007;
    int n;
    cin >> n;
    map<int, int> mp = {{0, 3}};
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans *= mp[x];
        ans %= mod;
        mp[x]--;
        mp[x + 1]++;
    }
    cout << ans << endl;
}
