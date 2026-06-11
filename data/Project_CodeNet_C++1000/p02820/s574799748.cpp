#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
using namespace std;

using   ll=long long;
using   ld=long double;

#define fast        	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ordered_set 	tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>

#define endl        	"\n"
#define pb          	push_back
#define mp          	make_pair
#define F           	first
#define S           	second
#define int 			long long int
#define pll 			pair<ll , ll>

#define ALL(v)      	v.begin(),v.end()
#define ALLR(v)     	v.rbegin(),v.rend()
#define pii         	3.14159265358979323
#define inf     		LLONG_MAX
#define ones(x)     	__builtin_popcount(x)
#define fill(a,b)   	memset(a,b,sizeof(a))
#define mod 			1000000007

ll mod_pow(ll a,ll b) {
    ll res = 1;
    while(b)	
    {
        if(b&1) 	
        {
        	res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

ll mod_inverse(ll a) {
	return mod_pow(a , mod-2);
}

void solve() {
    
    int n , k;
    
    int r , s , p;
    
    string t;
    
    cin >> n >> k;
    
    cin >> r >> s >> p;
    
    map<char , int> f;
    
    f['r'] = p;
    f['s'] = r;
    f['p'] = s;
    
    cin >> t;
    
    int dp[n+5] {};
    
    for(int i = 0; i < n; ++i) {
    	if(i-k >= 0) {
    		if(i - 2*k >= 0) {
    			if(t[i-k] != t[i]) {
    				dp[i] = dp[i-k] + f[t[i]];
    			}
    			else {
    				dp[i] = max(dp[i-k] , dp[i-2*k] + f[t[i]]);
    			}
    		}
    		else {
    			if(t[i-k] != t[i]) {
    				dp[i] = dp[i-k] + f[t[i]];
    			}
    			else {
    				dp[i] = max(dp[i-k] , f[t[i]]);
    			}
    		}
    		
    	}
    	else {
    		dp[i] = f[t[i]];
    	}
    }
    
    int sm = 0;
    
    for(int i = n-1; i >= 0 && k > 0; --k , --i) {
    	sm += dp[i];
    }
    
    cout << sm;
}       

signed main() {
    fast;
    
    int t = 1;
    
    //cin >> t;
    
    while(t--) {
        solve();
    }
 
    return 0;
}
