#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n;

int main() {
    cin >> n;
    if(n%2 != 0) cout << 0 << endl;
    else {
        ll now = 10;
        ll cnt = 0;
        while(now <= n) {
            cnt += (n/now);
            now *= 5;
        }
        cout << cnt << endl;
    }
}