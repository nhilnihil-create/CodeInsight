#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ll A, B;
    cin >> A >> B;
    cout << A*B/gcd(A, B) << endl;
    return 0;
}