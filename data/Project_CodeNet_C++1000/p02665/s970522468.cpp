#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n;
vector<ll> A(100100, 0);

int main() {
    cin >> n;
    for(int i = 0; i <= n; ++i) cin >> A.at(i);

    vector<ll> sumleft(n+2, 0);
    vector<ll> sumright(n+2, 0);
    for(int i = n; i >= 0; --i) {
        if(i == n) {
            sumleft.at(n) = A.at(n);
            sumright.at(n) = A.at(n);
        }else {
            sumleft.at(i) = (sumleft.at(i+1)+1)/2 + A.at(i);
            sumright.at(i) = sumright.at(i+1) + A.at(i);
        }
    }

    if(sumright.at(0) >= 1 && sumleft.at(0) <= 1) {
        ll ans = 0;
        ll limit = 1;
        for(int i = 0; i <= n; ++i) {
            if(i == 0) {
                ans += 1;
                limit *= 2;
            }else {
                ll cnt = min(limit, sumright.at(i));
                ans += cnt;
                cnt -= A.at(i);
                limit = cnt*2;
            }
            // cout << "i ans " << i << " " << ans << endl;
            // cout << "limi " << limit << endl;
        }
        cout << ans << endl;
    }else {
        cout << -1 << endl;
    }
}