#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main(void) {
    ll N;
    cin >> N;
    vector<ll> A(N);

    for (ll i = 0; i < N; i++)
        cin >> A[i];

    map<ll, ll> l, r;
    for (ll i = 0; i < N; i++) {
        l[i - A[i]]++;
        r[i + A[i]]++;
    }
    ll ans = 0;
    for (auto p : r) {
        ans += p.second * l[p.first];
    }
    cout << ans << endl;
}
