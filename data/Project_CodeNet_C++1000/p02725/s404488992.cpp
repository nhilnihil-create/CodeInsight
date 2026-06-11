#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll k, n;
    cin >> k >> n;

    vector<ll> ai(n);
    vector<ll> di(n);
    for (int i = 0; i < n; i++) {
        cin >> ai.at(i);
    }
    for (int i = 0; i < n-1; i++) {
        di.at(i) = ai.at(i+1) - ai.at(i);
    }
    di.at(n-1) = k -ai.at(n-1) + ai.at(0);
    ll dmax = 0;

    for (ll i: di) dmax = max(i, dmax);
    cout << k - dmax << endl;

    return 0;
}