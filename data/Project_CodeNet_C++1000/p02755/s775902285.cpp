#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll A, B;
    cin >> A >> B;

    for(ll x = 10*B; x < 10*B + 10; ++x) {
        if((ll)(0.08*x) == A) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}