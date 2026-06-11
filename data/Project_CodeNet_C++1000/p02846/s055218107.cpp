#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll p = (a1-b1)*t1, q = (a2-b2)*t2;
    if(p > 0) {
        p *= -1; q *= -1;
    }

    if(p+q < 0) cout << 0 << endl;
    else if(p+q == 0) cout << "infinity" << endl;
    else {
        if(-p%(p+q) == 0) cout << -p/(p+q)*2 << endl;
        else cout << -p/(p+q)*2 + 1 << endl;
    }
}