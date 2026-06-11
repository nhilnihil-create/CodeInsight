#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    vector<ll> a(n + 1, 0);
    vector<ll> b(m + 1, 0);

    ll sum_a = 0;
    ll sum_b = 0;
    ll max_a = -1;
    ll max_b = -1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum_a += a[i];
        a[i] = sum_a;

        if(sum_a <= k) max_a = i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        sum_b += b[i];
        b[i] = sum_b;

        if(sum_b <= k) max_b = i;
    }


    int ans = 0;

    if(a[n] + b[m] <= k) ans = n + m;
    for(int i = 0; i <= max_a; i++) {
        ll temp = k - a[i];
        vector<ll>::iterator it;

        it = upper_bound(b.begin(), b.begin() + max_b + 1, temp);
        ans = max(ans, i + (int) (it - b.begin() - 1));
    }

    cout << ans << endl;




    return 0;
}