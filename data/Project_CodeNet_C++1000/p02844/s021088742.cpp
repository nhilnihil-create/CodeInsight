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

    string S;
    cin >> S;

    vector<char> p(3);
    ll ans = 0 , d, tmp;

    rep(i, 1000) {
        tmp = i;
        rep(j, 3) {
            d = pow(10, 2 - j);
            p[j] = tmp / d + '0';
            tmp %= d;
        }
        ll x = 0, y = 0;
        while(x != N){
            if (S[x] == p[y]) y++;
            if (y == 3) {
                ans++;
                break;
            }
            x++;
        }
    }
    cout << ans;

    return 0;
}



ll gcd(ll a, ll b) {
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}