#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    vector<ll> num(n+1);
    num[0] = 0;
    ll cnt = 0;
    rep(i, n) {
        if (s[i] == '<') {
            ++cnt;
            num[i+1] = cnt;
        }
        else {
            cnt = 0;
        }
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1 && s[i] == '>') {
            num[i+1] = 0;
        }
        if (s[i] == '>') {
            ++cnt;
            num[i] = max(num[i], cnt);
        }
        else {
            cnt = 0;
        }
    }
    for (auto nn: num) {
        ans += nn;
    }
    cout << ans << endl;
    return 0;
}
