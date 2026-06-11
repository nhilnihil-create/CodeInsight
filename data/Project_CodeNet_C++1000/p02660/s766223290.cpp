#include <bits/stdc++.h>


using namespace std;

using ll = long long;


void prime_factorize(ll N, vector<pair<ll, ll>> &res) {
    for (ll i = 2; i * i <= N; i++) {
        if (N % i != 0)
            continue;
        ll e = 0;
        while (N % i == 0) {
            e++;
            N /= i;
        }
        res.push_back(make_pair(i, e));
    }
    if (N != 1)
        res.push_back(make_pair(N, 1));
}


ll seq_sum(ll N) {
    return N * (1 + N) / 2;
}


int main(void) {
    vector<ll> seq_sum_values;
    ll n = 1;
    ll sum_now = seq_sum(n++);
    seq_sum_values.push_back(sum_now);
    while (sum_now < (ll)1e12) {
        sum_now = seq_sum(n++);
        seq_sum_values.push_back(sum_now);
    }

    ll N;
    cin >> N;
    ll ans = 0;
    vector<pair<ll, ll>> res;
    prime_factorize(N, res);
    for (auto r : res) {
        ll p = r.first;
        ll e = r.second;
        auto it = upper_bound(seq_sum_values.begin(), seq_sum_values.end(), e);
        ans += distance(seq_sum_values.begin(), it);
    }
    cout << ans << endl;
}
