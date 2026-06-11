#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

    string S;
    ll K, N;

    cin >> S >> K;
    
    N = S.size();

    vector<ll> c;
    ll tmp = 1;

    repl(i, 1, N) {
        if (S[i - 1] == S[i]) {
            tmp++;
            if (i == N - 1) {
                c.push_back(tmp);
            }
        }
        else{
            c.push_back(tmp);
            tmp = 1;
        }
    }

    if (N == 1) {
        c.push_back(1);
    }

    ll ans = 0;
    ll n = c.size();
    
    rep(i, n) {
        ans += c[i] / 2;
    }

    ans = ans * K;

    if (S.front() == S.back()) {
        ans = ans - (c.front() / 2 + c.back() / 2 - (c.front() + c.back()) / 2) * (K - 1);
    }


    if (n == 1) {
        ans = c.front() * K / 2;
    }

    cout << ans;

    return 0;
}