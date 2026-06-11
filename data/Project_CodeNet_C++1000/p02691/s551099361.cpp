#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
using less_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using great_set = tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const int N = 2e3+69;
#define ALL(x) begin(x),end(x)
#define sz(x) (ll)x.size()
const int OO = 0x3f3f3f3f;
const int mod = 1e9+7;


int n;
int arr[200069];
map<ll, ll> cum;


int main()
{
    FIO
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i< n; i++)
        cum[i+arr[i]]++;
    for(int i = 0; i< n; i++)
        ans += cum[i-arr[i]];
    cout << ans << "\n";

    return 0;
}
