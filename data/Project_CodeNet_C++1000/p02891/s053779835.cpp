#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

// can't

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    vector<ll> cnt(n, 1);

    int j = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt[j]++;
        else j++;
    }

    ll ans = 0;
    if (j == 0) ans = cnt[0] * k / 2;
    else {
        for(int i = 0; i <= j; i++) ans += cnt[i] / 2;
        ans *= k;
        if (s[0] == s[n-1]) {
            ll fix = cnt[0] / 2 + cnt[j] / 2 - (cnt[0] + cnt[j]) / 2;
            ans -= fix * (k - 1);
        }
    }

    cout << ans << endl;
}