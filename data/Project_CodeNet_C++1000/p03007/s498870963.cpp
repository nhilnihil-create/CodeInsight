#include <iostream>
#include <fstream>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

ll n;
vector<ll> a;

int main() {
    cin >> n;
    a.resize(n);
    for (auto &e:a) cin >> e;
    sort(a.begin(), a.end());
    multiset<ll> pos, neg;
    for (ll i = 1; i < n - 1; i++) {
        if (a[i] >= 0) pos.insert(a[i]);
        else neg.insert(a[i]);
    }
    pos.insert(a[n - 1]);
    neg.insert(a[0]);
    vector<pair<ll, ll>> h;
    while (!neg.empty()) {
        ll p = *(pos.begin()), q = *(neg.begin());
        pos.erase(pos.begin());
        neg.erase(neg.begin());
        if (pos.size() <= neg.size()) {
            pos.insert(p - q);
            h.emplace_back(p, q);
        } else {
            neg.insert(q - p);
            h.emplace_back(q, p);
        }
    }
    cout << *(pos.begin()) << endl;
    for (auto e:h) {
        cout << e.first << ' ' << e.second << endl;
    }
}
