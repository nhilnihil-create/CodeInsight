#include <bits/stdc++.h>


using namespace std;

using ll = long long;


int main(void) {
    ll N;
    cin >> N;
    vector<ll> a(N + 1);
    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
    }

    ll acc = 0;
    for (ll i = 1; i <= N; i++) {
        acc ^= a[i];
    }

    vector<ll> cats(N + 1);
    for (ll i = 1; i <= N; i++) {
        cats[i] = acc ^ a[i];
    }

    for (ll i = 1; i <= N; i++) {
        cout << cats[i] << " ";
    }
    cout << endl;
}
