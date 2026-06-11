#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;
    map<ll, ll> mp;
    mp[0]++;
    ll res = 0;
    if(P == 2) {
        for(ll i = 0; i < N; i++) {
            if((int)(S[i] - '0') % 2 == 0) {
                res += i + 1;
            }
        }
    } else if(P == 5) {
        for(ll i = 0; i < N; i++) {
            if((int)(S[i] - '0') % 5 == 0) {
                res += i + 1;
            }
        }
    } else {
        ll num = 0;
        ll coef = 1;
        for(int i = N - 1; i >= 0; i--) {
            num += (ll)(S[i] - '0') * coef;
            num %= P;
            res += mp[num];
            mp[num]++;
            coef = (coef * 10) % P;
        }
    }
    cout << res << endl;
    return 0;
}