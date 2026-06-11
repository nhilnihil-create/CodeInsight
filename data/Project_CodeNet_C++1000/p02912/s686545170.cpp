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
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll dx[] = { 1,0 };
ll dy[] = { 0,1 };

int main() {

    ll N, M;

    cin >> N >> M;

    priority_queue<ll> A;

    ll tmp;

    rep(i, N) {
        cin >> tmp;
        A.push(tmp);
    }

    rep(i, M) {
        if (A.top() == 0) break;
        tmp = A.top() / 2;
        A.pop();
        A.push(tmp);
    }


    ll ans = 0;
    rep(i, N) {
        ans += A.top();
        A.pop();
    }

    cout << ans;

    return 0;
}