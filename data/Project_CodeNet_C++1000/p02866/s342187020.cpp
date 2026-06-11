#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> p;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {

    ll N;
    cin >> N;

    vector<ll> cnt(N, 0);
    ll T = 0, tmp, D = 998244353;
    bool flag = true;

    cin >> tmp;

    if (tmp != 0) {
        flag = false;
    }

    rep(i, N - 1) {
        cin >> tmp;
        if (tmp == 0) flag = false;        
        T = max(T, tmp);
        cnt[tmp]++;
    }

    ll ans = 1;

    if (flag) {
        repl(i, 2, T + 1) {
            rep(j, cnt[i]) {
                ans *= cnt[i - 1];
                if (ans > D) ans %= D;
            }
        }
    }
    else {
        ans = 0;
    }

    cout << ans;

}



ll gcd(ll a, ll b) {
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}