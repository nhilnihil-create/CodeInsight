#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll S = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> x;
    for (ll i = 1; i*i <= S; i++) {
        if (i*i == S) {
            x.push_back(i);
        }
        else {
            if (S % i == 0) {
                x.push_back(i);
                x.push_back(S/i);
            }
        }
    }
    sort(x.begin(), x.end());
    ll ans = 1;
    for (auto g: x) {
        ll k = 0;
        vector<ll> v;
        for (auto a: A) {
            if (a % g == 0) continue;
            k += (a/g+1)*g-a;
            v.push_back((a/g+1)*g-a);
        }
        if (k % g != 0) continue;
        sort(v.begin(), v.end(), [](auto x, auto y) {
            return x > y;
        });
        ll e = 0;
        for (int i = (k/g); i < v.size(); i++) {
            e += v[i];
        }
        if (e <= K) {
            ans = g;
        }
    }
    cout << ans << endl;
}