#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    vector<ll> t(N);
    ll ans = 1;
    for (ll x : divisor(sum)) {
        t = A;
        for (int i = 0; i < N; i++) {
            t[i] %= x;
        }
        sort(t.begin(), t.end());
        vector<ll> lef(N); lef[0] = t[0];
        for (int i = 1; i < N; i++) lef[i] = lef[i-1] + t[i];
        vector<ll> rig(N); rig[N-1] = x - t[N-1];
        for (int i = N-2; 0 <= i; i--) rig[i] = rig[i+1] + (x - t[i]);
        ll k = 10000000000;
        for (int i = 1; i < N; i++) {
            if (lef[i-1] == rig[i]) k = lef[i-1];
        }
        if (k <= K) ans = max(ans, x);
    }
    cout << ans << endl;
}