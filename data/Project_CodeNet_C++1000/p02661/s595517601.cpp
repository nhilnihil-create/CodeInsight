#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
using less_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using great_set = tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const int N = 2e3+69;
#define ALL(x) begin(x),end(x)
#define sz(x) (ll)x.size()
const int OO = 0x3f3f3f3f;
const int mod = 1000000007;


int n;
int a[200069];
int b[200069];


int main()
{
    FIO
    cin >> n;
    for(int i = 0; i< n; i++)
        cin >> a[i] >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    cout << (n%2 ? (b[n/2]-a[n/2]+1) : b[n/2] + b[n/2-1] - a[n/2] - a[n/2-1] + 1)<< "\n";
    return 0;
}
