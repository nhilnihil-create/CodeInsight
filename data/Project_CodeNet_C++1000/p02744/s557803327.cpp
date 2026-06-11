#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

ll n;
vl v;

void check(vl &v) {
    rep(i, n) {
        char c = v[i] + 'a';
        cout << c;
    }
    cout << "\n";
}

void dfs(ll depth, ll ma) {
    if(depth == n) {
        check(v);
        return;
    }
    exrep(i, 0, ma+1) {
        v[depth] = i;
        if(i == ma+1) {
            dfs(depth+1, ma+1);
        }
        else {
            dfs(depth+1, ma);
        }
    }
}

int main() {

    cin >> n;

    v.resize(n);
    dfs(0, -1);

    re0;
}