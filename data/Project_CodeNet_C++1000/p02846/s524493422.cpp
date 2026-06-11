#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll x = (a1 - b1) * t1;
    ll y = (a2 - b2) * t2;
    if(x > 0){
        x *= -1;
        y *= -1;
    }
    if(x+y == 0){
        cout << "infinity" << endl;
        return 0;
    }
    if(x+y < 0){
        cout << 0 << endl;
        return 0;
    }
    ll z = (-x) / (x+y);
    if((-x)%(x+y)) cout << (z*2 + 1LL) << endl;
    else cout << z*2 << endl;
    return 0;
}
