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

void solvetask() {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) if(s[i] != t[i]) ans++;
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);

    int t = 1;

    while(t--) solvetask();
}
