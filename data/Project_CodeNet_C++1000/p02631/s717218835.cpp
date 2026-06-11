#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define orderd_set tree<pair<int, int>, null_type,greater<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
//find_by_order(k)
//order_of_key(k)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const int N = 2e3+69;
#define ALL(x) begin(x),end(x)
#define sz(x) (ll)x.size()
const int OO = 0x3f3f3f3f;
const int mod = 1000000007;

int n;
ll arr[200069];


int main()
{
    FIO
    cin >> n;
    ll num = 0;
    for(int i= 0; i< n; i++)
    {
        cin >> arr[i];
        num ^= arr[i];
    }
    //cout << num << "\n";
    for(int i = 0; i< n; i++)
    {
        cout << (ll)(arr[i]^num) << " ";
    }
    return 0;
}
