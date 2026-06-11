#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll SIZE = 2e5+200;

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll curr = 1;

    for (auto x : arr) {
        if (x == curr) {
            curr++;
        }
    }

    if (curr == 1) {
        cout << -1 << endl;
    } else {
        cout << n-curr+1 << endl;
    }
}