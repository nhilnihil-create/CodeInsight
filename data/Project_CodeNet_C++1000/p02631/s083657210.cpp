#include "bits/stdc++.h"

using namespace std;
using ll = long long;
#define endl '\n'
#define all(v) v.begin(), v.end()

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& v : a) cin >> v;
    ll S = a[0];
    for (int i = 1; i < n; i++)
        S ^= a[i];
    for (ll& v : a)
        cout << (S ^ v) << " ";
    cout << endl;
}
