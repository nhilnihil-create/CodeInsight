#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll dp(ll h) {
    ll ans;

    if(h == 1) {
        ans = 1;
    } else {
        ans = 2*dp(h/2) + 1;
    }

    return ans;
}

int main() {
    ll H;
    cin >> H;

    if(H == 1) {
        cout << 1 << endl;;
    } else {
        cout << 2*dp(H / 2) + 1 << endl;
    }

    return 0;
}