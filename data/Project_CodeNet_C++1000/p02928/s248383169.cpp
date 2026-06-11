#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) if (a[i] > a[j]) ans++;
    }
    ans = ans * k % MOD;

    sort(a.begin(), a.end());

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        auto itr = lower_bound(a.begin(), a.end(), a[i]);
        cnt += itr - a.begin();
        cnt %= MOD;
    }

    ll t = k * (k - 1) / 2 % MOD;
    ans += cnt * t % MOD;
    cout << ans % MOD << endl;
}