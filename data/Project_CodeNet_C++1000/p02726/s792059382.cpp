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

    ll N, X, Y;
    cin >> N >> X >>Y;

    vector<vector<ll>> G(N + 1, vector <ll>(N + 1, mod));

    repl(i, 1, N) {
        repl(j, i + 1, N + 1) {
            G[i][j] = min(j - i, abs(X - i) + abs(Y - j) + 1);
        }
    }

    vector<ll> cnt(N + 1, 0);


    repl(i, 1, N) {
        repl(j, i + 1, N + 1) {
            cnt[G[i][j]]++;
        }
    }

    repl(i, 1, N) {
        cout << cnt[i] << endl;
    }

    return 0;
}



ll gcd(ll a, ll b) {
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}