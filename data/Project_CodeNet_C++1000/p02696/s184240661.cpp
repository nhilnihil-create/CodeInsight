#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
  
          
using namespace std;
using namespace __gnu_pbds;
 
  
 
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")*/
      
#define int long long
#define eb emplace_back
#define pb push_back
#define ld long double
#define mp make_pair
#define f first
#define s second
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(5); \
    cerr << fixed << setprecision(11); \
}
 
template < typename firstType, typename secondType = null_type, class compare = less < firstType > >
struct sett {
    typedef tree <
        firstType,
        secondType,
        compare,
        rb_tree_tag,
        tree_order_statistics_node_update
    > _ ;
};
 
  
const int INF = 1e9 + 7;
const ld EPS = 1e-10;
const int MAXI = 200000;
const int P = 223; 
const int MOD = 998244353; 
const int MAXST = 2000000;
const ld PI = 3.14159265358979323;
        
ostream &operator<<(ostream &stream, const pair <int, int> &p) {
    stream << p.first << ' ' << p.second << ' ';
    return stream;
}



signed main(){  
    fast();
    srand(time(0));
    #ifdef _LOCAL               
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int a, b, n;
    cin >> a >> b >> n;
    int ans = min(b - 1, n);
    cout << a * ans / b - a * (ans / b);
    return 0;                   
   	
}