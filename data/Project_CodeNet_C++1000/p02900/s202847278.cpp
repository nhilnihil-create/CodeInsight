#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

map<ll, ll> prime_factor(ll n){
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; ++i) {
        while(n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main(){
    ll a, b;
    cin >> a >> b;

    ll g = gcd(a, b);
    auto mp = prime_factor(g);
    cout << mp.size() + 1 << endl;
}