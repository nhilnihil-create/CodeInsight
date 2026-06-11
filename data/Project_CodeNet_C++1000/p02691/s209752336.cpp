#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    map<ll, ll> l;
    map<ll, ll> r;
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        l[a + i]++;
        r[i - a]++;
    }

    ll output = 0;
    for (auto e : l) {
        output += r[e.first] * e.second;
    }
    cout << output << endl;

    return 0;
}
