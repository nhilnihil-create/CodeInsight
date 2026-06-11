/* Author: Rennan Rocha
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>

#define INF 1e18
#define MOD 1000000007
//#define DEBUG

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order(); order_of_key();

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine e(seed);
std::mt19937 rng((int) seed);

ll a[200010];
ll b[200010];

void solvetask() {
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 0) a[i] += a[i-1];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        if(i > 0) b[i] += b[i-1];
    }

    ll ans = int(upper_bound(b, b + m, k) - b);

    for(int i = 0; i < n; i++) {
        if(a[i] > k) break;
        ll at = int(upper_bound(b, b + m, k - a[i]) - b) + i + 1;
        ans = max(ans, at);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    int t = 1;

    while(t--) solvetask();
}
