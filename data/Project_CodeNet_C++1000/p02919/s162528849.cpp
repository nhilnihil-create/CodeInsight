#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int pi;
        cin >> pi;
        mp[pi] = i;
    }

    multiset<int> ms;
    ms.insert(-1);
    ms.insert(-1);
    ms.insert(N);
    ms.insert(N);
    ll ans = 0;
    for (int i = N; i >= 1; i--) {
        int a = mp[i];
        auto itr = ms.insert(a);
        int w, x, y, z;
        x = *(--itr);
        w = *(--itr);
        ++itr, ++itr;
        y = *(++itr);
        z = *(++itr);
        ans += (ll)(x - w) * (y - a) * i;
        ans += (ll)(a - x) * (z - y) * i;
    }

    cout << ans << endl;


    return 0;
}