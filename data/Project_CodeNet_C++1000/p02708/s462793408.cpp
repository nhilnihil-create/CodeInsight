#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

ll sum(int l, int r) {
    return ll(l+r)*(r-l+1)/2;
}

int main() {
    int n,k;
    cin >> n >> k;

    ll ans = 0;
    for (int i = k; i <= n+1; i++) {
        ll min_sum = sum(0, i-1);
        ll max_sum = sum(n-i+1, n);
        ll t = max_sum - min_sum + 1;
        ans += t % (1000000000 + 7);
    }

    cout << ans % (1000000000+7) << endl;

    return 0;
}