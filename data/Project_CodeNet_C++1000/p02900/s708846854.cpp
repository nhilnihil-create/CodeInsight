#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

map<ll, int> prime_factor(ll N) {
    map<ll, int> RES;
    for (ll I = 2; I*I <= N; I++) {
        while (N%I == 0) {
            RES[I]++;
            N /= I;
        }
    }
    if (N != 1) RES[N] = 1;
    return RES;
}

int main() {
    ll a,b; cin >> a >> b;
    map<ll, int> ap = prime_factor(a);
    map<ll, int> bp = prime_factor(b);
    int ans = 1;
    for(auto itr = ap.begin(); itr != ap.end(); itr++) {
        if (bp[itr->first] != 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
