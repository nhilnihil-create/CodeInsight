#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i <= n - 1; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    ll tot = 0;
    for (int i = k; i <= n - 1; i++) {
        tot += v[i];
    }
    cout << tot << '\n';
}