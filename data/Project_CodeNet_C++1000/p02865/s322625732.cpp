#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define IN freopen("C.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define INF 1000000000
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef pair<int, int> pi ;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define maxn 100005

/*
     *os.find_by_order(k) -> returns the k'th smallest element (indexing starts from 0)
      os.order_of_key(v)  -> returns how many elements are strictly smaller than v
*/

int main()
{
    int n ;
    scanf("%d",&n) ;

    printf("%d\n" , (n-1)/2 ) ;

    return 0 ;
}
