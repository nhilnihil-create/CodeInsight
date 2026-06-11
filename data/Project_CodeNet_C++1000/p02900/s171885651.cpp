#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

ll mod = 1e9 + 7ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll inf = 1ll << 60;

ll gcd(ll n, ll m) {
    // nとmの最大公約数を返す関数
    if(m > n) {
        ll c = n;
        n = m; 
        m = c;
    }
    if(n%m == 0) return m;
    else return gcd(m, n%m);
}

vector< pair<ll, ll> > prime_factorize(ll n) {
    // 素因数分解アルゴリズム
    vector< pair<ll, ll> > res;
    for(ll a = 2; a*a <= n; ++a) {
        if(n % a != 0) continue;
        ll ex = 0;
        while(n % a == 0) {
            ++ex;
            n /= a;
        }
        res.push_back({a, ex});
    }
    if(n != 1) res.push_back({n, 1});
    return res;
}

int main(){
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll g = gcd(n, m);
    vector< pair<ll, ll> > prime = prime_factorize(g);
    printf("%d\n", int(prime.size()) + 1);
    return 0;
    
}