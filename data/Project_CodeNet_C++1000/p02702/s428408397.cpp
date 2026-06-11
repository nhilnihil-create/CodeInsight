#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;
const int inf = 2e9;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

int main() {
    string S;
    getline(cin, S);

    vector<ll> modcounts(2019, 0);
    ll premod = 0;
    ll tensmod = 1;
    for (ll i = S.length() - 1; i >= 0; i--) {
        ll c = (ll)S.at(i) - '0';
        ll m = (c * tensmod + premod) % 2019;
        modcounts[m]++;
        tensmod = (tensmod * 10) % 2019;
        premod = m;
    }
    ll result = 0;
    for (ll m = 0; m < modcounts.size(); m++) {
        if (m == 0 && modcounts[m] >= 1) {
            result += (modcounts[m] + 1) * modcounts[m] / 2;
        } else if (modcounts[m] >= 2) {
            result += modcounts[m] * (modcounts[m] - 1) / 2;
        }
    }
    print(result);
}
