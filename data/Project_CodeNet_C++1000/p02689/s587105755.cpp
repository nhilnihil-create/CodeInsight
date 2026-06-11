#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    int n, m;
    cin >> n >> m;

    vi h(n), good(n, 1);

    for(int& i : h) cin >> i;

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if(h[a] > h[b]) good[b] = 0;
        else if(h[a] < h[b]) good[a] = 0;
        else good[a] = good[b] = 0;
    }

    cout << count(ALL(good), 1) << endl;
    
    return 0;
}