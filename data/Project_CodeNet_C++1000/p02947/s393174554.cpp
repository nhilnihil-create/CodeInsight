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

ll combination(ll x);


int main() {

    ll N;

    cin >> N;


    vector<string> S(N);

    rep(i, N) {
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
    }

    ll a, b;
    a = S.size();

    sort(S.begin(), S.end());

    S.push_back("end");

    string tmp = "aa";
    ll count = 0, ans = 0;

    rep(i, N + 1) {
        if (tmp == S[i]) {
            count++;
        }
        else {
            if (count > 1) {
                ans += combination(count);
            }
            count = 1;
            tmp = S[i];
        }
    }

    cout << ans;
    
    return 0;
}

ll combination(ll x) {
    ll ans;
    ans = x * (x - 1) / 2;
    return ans;
}
