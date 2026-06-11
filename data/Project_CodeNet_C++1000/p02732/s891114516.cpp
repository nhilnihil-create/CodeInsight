#include <bits/stdc++.h>


using namespace std;


using ll = long long;


const long long MAX = 200001;


long long fact[MAX];


void calc_fact() {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= MAX; i++) {
        fact[i] = (fact[i - 1] * i);
    }
}


ll comb2(ll n) {
    if (n < 2)
        return 0;
    return (n * (n - 1)) / 2;
}


int main(void) {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    calc_fact();

    vector<ll> cnt(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        cnt[A[i]]++;
    }

    ll acc = 0;
    for (ll i = 1; i <= N; i++) {
        acc += comb2(cnt[i]);
    }

    for (ll k = 0; k < N; k++) {
        ll ans = acc - comb2(cnt[A[k]]) + comb2(cnt[A[k]] - 1);
        cout << ans << endl;
    }
}
