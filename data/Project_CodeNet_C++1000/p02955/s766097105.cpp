#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    vector<ll> cand;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            cand.push_back(i);
            cand.push_back(sum / i);
        }
    }

    ll ans = 0;
    for (ll c : cand) {
        vector<int> r(N);
        for (int i = 0; i < N; i++) {
            r[i] = A[i] % c;
        }
        sort(r.begin(), r.end());
        for (int i = 1; i < N; i++) {
            r[i] += r[i - 1];
        }

        bool ok = false;
        for (int i = 0; i < N - 1; i++) {
            ll minus = r[i];
            ll plus = c * (N - i - 1) - (r[N - 1] - r[i]);
            if (plus < minus)
                swap(plus, minus);

            if ((plus - minus) % c == 0 && plus <= K) {
                ok = true;
            }
        }
        if (ok) {
            ans = max(ans, c);
        }
    }

    cout << ans << endl;
}
