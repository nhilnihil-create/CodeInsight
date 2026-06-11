#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 8;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define Graph vector<vector<int>>
#define rng(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rnr(i, a, b) for(ll i = ll(a); i >= ll(b); i--)
#define rep(i, b) rng(i, 0, b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

ll modpow(ll a, ll n) {
    //ret a^n;
    ll ret = 1;
    rep(i, n) {
        ret = (ret * a) % MOD;
    }
    return ret;
}

int main() {
    ll n; cin >> n;
    cout << (modpow(10, n) - 2 * modpow(9, n) + modpow(8, n) + 3 * MOD) % MOD << endl;
}
