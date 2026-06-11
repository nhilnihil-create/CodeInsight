#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<pair<ll, ll>> A(N);
    for (int i = 0; i < N; ++i) {
        ll x, l;
        cin >> x >> l;
        A[i] = make_pair(x + l, x - l);
    }

    sort(A.begin(), A.end(), greater<pair<ll, ll>>());

    int ans = 0;
    ll left = 1e+13;
    for (auto p : A) {
        if(p.first <= left)
        {
            left = p.second;
            ++ans;
        } else {
            left = max(left, p.second);
        }
    }
    cout << ans << endl;
}