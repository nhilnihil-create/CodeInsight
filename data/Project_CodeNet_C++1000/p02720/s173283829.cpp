#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    ll K;
    cin >> K;

    queue<ll> q;
    for(ll i = 1; i <= 9; ++i) {
        q.push(i);
    }

    FOR(i, 1, K) {
        ll tmp = q.front();
        q.pop();
        
        if(tmp % 10 != 0) q.push((10*tmp) + (tmp % 10) - 1);
        q.push((10*tmp) + (tmp % 10));
        if(tmp % 10 != 9) q.push((10*tmp) + (tmp % 10) + 1);
    }

    cout << q.front() << endl;

    return 0;
}