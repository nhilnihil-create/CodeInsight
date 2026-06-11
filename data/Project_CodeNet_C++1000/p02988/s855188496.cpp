#include <bits/stdc++.h>
using namespace std;

#define INDEXED_SET 0

#if INDEXED_SET
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
//find_by_order(i) - iterator to i-th element
//order_of_key(x) - x's index in the set
#endif

#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define leading_0s(x) __builtin_clz(x)  //left 0s
#define trailing_0s(x) __builtin_ctz(x) //right 0s
#define count_1s(x) __builtin_popcount(x)
#define parity_1s(x) __builtin_parity(x) // 0 = even, 1 = odd
#define FORI(i,a,b) for (int i = int((a)); i <= int((b)); i++)
#define FORD(i,a,b) for (int i = int((a)); i >= int((b)); i--)
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define endl '\n'
#define MAX 200005

using ll = long long;
using pi = pair<int,int>;
using pll = pair<long,long>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;

const int mod = 1e9 + 7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    FAST_IO;

    int n;
    cin >> n;
    vi v(n);
    for (auto &e:v)
        cin >> e;
    int ans = 0;
    FORI(i,1,n-2)
        ans += ((v[i-1] > v[i] && v[i-1] > v[i+1] && v[i] > v[i+1]) || (v[i+1] > v[i] && v[i+1] > v[i-1] && v[i] > v[i-1]));
    cout << ans << endl;
    return 0;
}