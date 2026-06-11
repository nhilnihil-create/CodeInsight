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

const int N = 5e3 + 2 ;
const int MOD = 1e9 + 7 ;
const lint INF = 1e18 ;

int n, k ;

int main()
{
    fastio;  cin >> n >> k ;
    vi cost(n+1, 0), p(n+1, 0);

    for(int i = 1; i <=n;++i) cin >> p[i] ;
    for(int i = 1; i <= n; ++i) cin >> cost[i] ;

    lint best = -2e9 ; 
    for(int i = 1; i <= n; i++) {
    	lint cur = 0 ; int j = i ; 
    	vector < lint >  exp(n+1, 0); vi seen(n+1, 0), succ;
    	int cnt = 0 ; 
    	while(!seen[p[j]]) {
    		int nxt = p[j] ; succ.pb(nxt);
    		cur += cost[nxt] ;
    		exp[nxt] = cur ; seen[nxt] = 1 ; 
    		j = nxt ; 
    	}
    	int len = sz(succ);
    	int rem = k % len ; 
    	int div = k / len ; 
    	lint cost2 = 0 ; lint curr = cur ;
    	if(cur > 0) {
    		cost2 = (curr * div) ; 
    		if(rem == 0)
    			cost2 = (curr * (div - 1));
    	}
    	if(rem == 0) rem = len ; 
    	for(int z = 0; z < rem; z++) {
    		reMax(best, cost2 + exp[succ[z]]);
    	}
    	for(int z = 0; z < min(k, len); z++)
    		reMax(best, exp[succ[z]]); 
    	// cout << i << " -- " << endl ; 
    	// for(int x : succ) cout << x << ": " << exp[x] << endl;
    	// 	cout << endl ; 
    }
    cout << best ; 
}
