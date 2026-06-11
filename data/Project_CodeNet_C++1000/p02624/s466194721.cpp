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

ll qtd[10000010];

void solvetask() {
    for(ll i = 1; i <= 10000000; i++) {
        for(ll j = i; j <= 10000000; j+=i) {
            qtd[j]++;
        }
    }
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ans += i * qtd[i];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    int t = 1;

    while(t--) solvetask();
}
