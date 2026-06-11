#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const ll mod = 1e9+7;
ll n;

int main() {
    cin >> n;
    vector<ll> A(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> A.at(i);
    }

    vector<ll> zero(65, 0);
    vector<ll> nzero(65, 0);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 63; ++j) {
            if(A.at(i)&((ll)1<<j)) {
                nzero.at(j)++;
            }else {
                zero.at(j)++;
            }
        }
    }

    ll ans = 0;
    ll now = 1;
    for(int i = 0; i < 63; ++i) {
        ll next = nzero.at(i)*zero.at(i);
        next %= mod;
        next *= now;
        next %= mod;
        now *= 2;
        now %= mod;
        ans += next;
        ans %= mod;
        // cout << "i " << ans << endl;
    }
    cout << ans << endl;
}