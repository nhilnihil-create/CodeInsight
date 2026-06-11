//Apparat : drobucs, aleonov, vit_72
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <stack>

//#pragma warning(disable : 4996)
//#pragma GCC optimize("O3")

using namespace std;

#define nptr nullptr
#define all(x) (x).begin(), (x).end()
#define drobucs ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define ff first
#define ss second
#define pbb push_back
#define sz(x) (int)(x).size()

typedef long long ll;

const int maxn = (int)1e6 + 13;
const ll INFL = 9e18 + 13ll;
const ll INF = 2e9 + 13;
const ll MOD = (int)1e9 + 7, MOD2 = 998244353;//1e9 + 21, 1e9 + 33, 1e9 + 87, 1e9 + 93
const ll base = 101, base2 = 37;

ll a[13][13];

int main() {
    drobucs;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int m = i;
        while (m >= 10)m /= 10;
        a[m][i % 10]++;
    }
    ll ans = 0;
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
            ans += a[i][j] * a[j][i];
    cout << ans << "\n";
    return 0;
}