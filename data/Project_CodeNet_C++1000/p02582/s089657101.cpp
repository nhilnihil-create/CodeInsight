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
#define F first 
#define S second 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef vector < int > vi ;
typedef pair < int, int > pii ;

// template <typename T>
inline int modpow(lint base, int exp, int modulo) {
  base %= modulo;
  lint result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo;
    exp >>= 1;
  }
  return result;
}

const int N = 1e6 + 2 ;
const int MOD = 1e9 + 7 ;
const lint INF = 1e18 ;

int main()
{
    fastio;
    string s ; cin >> s ;
    int mx = 0, cnt = 0 ;
    for(char x : s) {
    	if(x == 'R') {
    		cnt++;
    		reMax(mx, cnt); 
    	}
    	else cnt = 0 ;
    }
    cout << mx ; 
}
