#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std ;
using namespace __gnu_pbds;

template <typename T> // *s.find_by_order(0), s.order_of_key(2) ;
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define reMin(a, b) a = min(a, b)
#define reMax(a, b) a = max(a, b)

#define lint long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef vector < int > vi ;
typedef pair < int, int > pii ;

const int N = 1e6 + 2 ;
const int MOD = 1e9 + 7 ;
const lint INF = 1e18 ;

multiset < int > cur, rem, temp ;
int n, a[N] ;

int main()
{
    fastio; cin >> n ;
    for(int i = 0; i < (1 << n); i++)
    {
        cin >> a[i] ;
        rem.insert(a[i]);
    }

    cur.insert(*rem.rbegin());
    rem.erase(rem.find(*rem.rbegin()));

    for(int i = 1; i <= n; i++)
    {
        temp.clear();
        for(int x : cur)
        {
            auto it = rem.lower_bound(x);
            if(it == rem.begin())
            {
                cout << "No" ;
                return 0 ;
            }
            it-- ;
            temp.insert(*it);
            rem.erase(rem.find(*it));
        }
        for(int x : temp) cur.insert(x);
        // for(int x : cur) cout << x << " " ;
        // cout << endl ;
    }
    cout << "Yes" ;
}

