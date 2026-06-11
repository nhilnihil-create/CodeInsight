#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n, k;
llong a[200005];
llong s[200005];
map<llong, llong> mp;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        s[i] %= k;
    }
    
    llong ans = 0;
    mp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i - k >= 0) {
            mp[(s[i - k] - (i - k) % k + k) % k]--;
        }

        //if (mp[(s[i] - i % k + k) % k]) cout << i << ':' << mp[(s[i] - i % k + k) % k] << endl;
        ans += mp[(s[i] - i % k + k) % k];
        mp[(s[i] - i % k + k) % k]++;
    }

    cout << ans << endl;

    return 0;
}
