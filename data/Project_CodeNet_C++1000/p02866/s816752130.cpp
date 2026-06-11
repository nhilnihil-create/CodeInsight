#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

ll divpow(ll a, ll b, ll div) {
    ll ret = 1;
    a %= div;
    for (ll i = 0; i < b; i++) {
        ret *= a;
        ret %= div;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;

    ll div = 998244353;
    map<ll, ll> tree;
    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        if (i == 0 && tmp != 0) {
            cout << 0 << endl;
            return 0;
        }
        tree[tmp]++;
    }
    if (tree[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    ll output = 1;
    pair<ll, ll> before = make_pair(0, tree[0]);
    for (auto t : tree) {
        if (t.first == 0) continue;
        if (t.first != before.first + 1) {
            output = 0;
            break;
        }
        output *= divpow(before.second, t.second, div);
        output %= div;
        before = t;
    }
    cout << output << endl;

    return 0;
}
