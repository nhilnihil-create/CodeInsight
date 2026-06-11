#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n;
    vector<ll> cnt(n,0);
    for (ll i=1; i<n; i++) {
        cin >> x;
        cnt[x-1]++;
    }
    for (auto i : cnt) cout << i << endl;
    return 0;
}