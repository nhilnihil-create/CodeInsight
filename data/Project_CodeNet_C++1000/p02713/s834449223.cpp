#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main(){
    int K;
    cin >> K;

    ll res = 0;
    for (ll i = 0; i < K; ++i) {
        for (ll j = 0; j < K; ++j) {
            for (ll k = 0; k < K; ++k) {
                res += gcd(gcd(i+1, j+1), k+1);
            }
        }
    }
    cout << res << endl;
}