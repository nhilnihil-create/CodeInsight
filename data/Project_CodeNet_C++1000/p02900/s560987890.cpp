#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i != 0) continue;
        ll ex = 0;
        while (N % i == 0) {
            ++ex;
            N /= i;
        }
        res.push_back({i, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll A,B;
    cin >> A >> B;
    ll G = gcd(A,B);
    ll cnt=0;
    auto pf = prime_factorize(G);
    cout << pf.size() + 1 << endl;
    return 0;
}