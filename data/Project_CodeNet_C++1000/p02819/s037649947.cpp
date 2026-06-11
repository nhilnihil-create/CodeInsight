#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define INF (1 << 29)
const int mod = 1000000007;

bool isPrime(ll x) {
    ll i;
    if(x < 2)
        return 0;
    else if(x == 2)
        return 1;
    if(x % 2 == 0)
        return 0;
    for(i = 3; i * i <= x; i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}

int main() {
    ll X;
    cin >> X;
    for(ll i = X; i < 100005; i++) {
        if(isPrime(i)) {
            cout << i << endl;
            exit(0);
        }
    }
    return 0;
}