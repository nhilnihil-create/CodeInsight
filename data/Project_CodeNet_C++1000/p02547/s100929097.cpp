#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)
const ll mod = 1000000007;
const double pi = 3.14159265358979;

ll expo(ll a, ll b){
    ll ex = 1;
    rep(i, b){
        ex *= a;
    }
    return ex;
}

ll fact(ll a){
    ll fc = 1;
    REP(i, 1, a+1){
        fc *= i;
    }
    return fc;
}

int main() {
    ll n;
    cin >> n;
    vel a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    bool ans = false;
    rep(i, n - 2) {
        if (a[i] == b[i]) {
            if (a[i+1] == b[i+1]) {
                if (a[i+2] == b[i+2]) {
                    ans = true;
                    break;
                }
            }
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}