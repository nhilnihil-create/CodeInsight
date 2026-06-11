#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

vector<pair<ll, ll> > prime_factorize(ll N){
    vector<pair<ll, ll> > res;
    for(ll i = 2; i * i <= N; i++){
        if(N % i != 0) continue;
        ll ex = 0;
        while(N % i == 0){
            ex++;
            N /= i;
        }
        // 素数と指数をpush
        res.push_back({i, ex});
    }
    if(N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    ll a, b; cin >> a >> b;

    ll g = gcd(a, b);
    V<P<ll, ll> > v = prime_factorize(g);

    cout << v.size() + 1 << endl;

    return 0;
}
