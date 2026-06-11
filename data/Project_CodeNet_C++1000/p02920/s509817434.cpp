#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
multiset<ll> S;

int main() {
    cin >> N;
    ll n = pow(2, N);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        S.insert(-x);
    }
    S.insert(0);
    multiset<ll> slimes{*S.begin()};
    S.erase(S.begin());
    for (int i = 0; i < N; i++) {
        multiset<ll> s = slimes;
        for (auto itr = s.begin(); itr != s.end(); itr++) {
            ll life = *itr;
            auto x = S.upper_bound(life);
            if (*x) {
                slimes.insert(*x);
                S.erase(x);
            }
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}