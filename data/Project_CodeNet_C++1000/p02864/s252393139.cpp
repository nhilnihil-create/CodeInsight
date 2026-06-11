//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
   
//#include <x86intrin.h>
#include <bits/stdc++.h>   
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
#define F first
#define S second           
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define al 0x3F3F3F3F
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 123;
const ll inf = (ll)1e18 + 1;
 
const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
 
int n, k, dp[333][333], h[333]; 

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     
 
inline void Solve () {
   cin >> n >> k;     
   for (int i = 1; i <= n; i ++) cin >> h[i];
   for (int i = 0; i <= n; i ++)
      for (int j = 0; j <= n; j ++)
         dp[i][j] = inf;   
   for (int i = 1; i <= n; i ++) {
      for (int j = 0; j <= min (i, n - k); j ++) {
         if (j == 0) dp[i][j] = 0;
         else if (j == 1) dp[i][j] = h[i];
         else {
            for (int l = 1; l < i; l ++) {
               dp[i][j] = min (dp[i][j], dp[l][j - 1] + max (0ll, h[i] - h[l]));
            }
         }
      }  
   }
   int ans = inf;
   for (int i = 1; i <= n; i ++) ans = min (ans, dp[i][n - k]);
   cout << ans;
}
 
main () {                                       
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
   //cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}
       