/**
 *    author:  Taichicchi
 *    created: 12.09.2020 12:01:10
 **/

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll L, R;

    cin >> L >> R;

    ll ans;

    for (ll i = L; i <= min(R, L + 2019); ++i) {
        for (ll j = i + 1; j <= min(R, L + 2019); ++j) {
            ans = min(ans, (i * j) % 2019);
            if (ans == 0) break;
        }
    }

    cout << ans << endl;

    return 0;
}