#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    ll cnt[n+10] = {0};
    ll a[n+10];

    rep(i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll total = 0;
    for(ll i = 1; i <= n; i++) {
        if (cnt[i] == 0) continue;
        total += cnt[i] * (cnt[i] - 1) / 2;
    }

    rep(i, n) {
        cout << total - (cnt[a[i]] * (cnt[a[i]] - 1) / 2) + ((cnt[a[i]] - 1) * (cnt[a[i]] - 2) / 2) << endl;
    }


    return 0;
}