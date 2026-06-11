#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned ll
#define all(x) x.begin(), x.end()


typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const int N = 1e7 + 10, X = 1e6 + 100;
const ll M = 1e9 + 7;
const double eps = 1e-9;

ll ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll d = (ll) floor(log10(i)) + 1;
        if (d % 2 == 1)
            ans++;
    }
    cout << ans << endl;
}