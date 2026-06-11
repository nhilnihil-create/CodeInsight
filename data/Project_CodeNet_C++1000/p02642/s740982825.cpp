#include <bits/stdc++.h>


using namespace std;
using ll = long long;


int main(void) {
    ll N;
    cin >> N;
    vector<ll> A(N);

    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    ll max_a = *(A.end() - 1);
    vector<ll> count(max_a + 1, 0);
    for (auto a : A) {
        if (count[a] != 0) {
            count[a]++;
            continue;
        }
        for (ll i = a; i <= max_a; i += a) {
            count[i]++;
        }
    }

    ll ans = 0;
    for (auto a : A) {
        if (count[a] == 1)
            ans++;
    }
    cout << ans << endl;
}
