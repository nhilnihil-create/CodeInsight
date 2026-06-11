#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
#define REP(i, n) for (int64_t i = 0; i < (int64_t)n; i++)
#define REP_FOR(i, a, b) for (int64_t i = (int64_t)a; i < (int64_t)b; i++)
#define REP_REV(i, a, b) for (int64_t i = (int64_t)a; i > (int64_t)b; i--)
#define FORALL(v) (v).begin(), (v).end()
#define mp(a, b) make_pair(a, b)
#define eb(x) emplace_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int64_t, int64_t> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int64_t> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int64_t infi = 1147483600;
const ll infl = 4e18 + 5;
const char EOL = '\n';
//cout << fixed << setprecision(17) << res << endl;
const ll MOD = 998244353;

 #include <vector>
 
#define ll long long int

#define M 1000000007

int main() {
    ll n;
    cin >> n;
    vector<ll> P(n), Pos(n+1, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> P[i];
        Pos[P[i]] = i + 1;
    }

    ll res = 0;
    multiset<ll> s;
    s.insert(0);
    s.insert(0);
    s.insert(n+1);
    s.insert(n+1);

    for (ll now = n; now >= 1; now--){
        auto it = s.lower_bound(Pos[now]);
        ll pos_r = *it;

        it++;
        ll pos_rr = *it;

        it--;
        it--;
        ll pos_l = *it;

        it--;
        ll pos_ll = *it;

        res += now*(pos_r-Pos[now])*(pos_l-pos_ll);
        res += now*(pos_rr-pos_r)*(Pos[now]-pos_l);

        s.insert(Pos[now]);
    }
    cout<<res<<endl;
}
