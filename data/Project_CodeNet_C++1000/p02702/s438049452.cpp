#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    string S;
    cin >> S;

    reverse(S.begin(), S.end());

    map<ll, ll> table;

    ll sum = 0;
    ll x = 1;
    ll ans = 0;
    for (ll i = 0; i < S.size(); i++) {
        // cout << "sum: " << sum << endl;
        ++table[sum];
        ll d = S[i] - '0';
        sum = (sum + x * d) % 2019;
        ans += table[sum];
        x = (x * 10L) % 2019;
    }

    cout << ans << endl;

    return 0;
}
