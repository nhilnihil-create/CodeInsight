#include<bits/stdc++.h>

using namespace std;
using   ll=long long;

#define fast        	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define endl        	"\n"
#define pb          	push_back
#define mp          	make_pair
#define F           	first
#define S           	second
#define int             long long int
#define pll				pair<int , int>

#define ALL(v)      	v.begin(),v.end()
#define ALLR(v)     	v.rbegin(),v.rend()
#define pii         	3.14159265358979323
#define inf     		LLONG_MAX
#define ones(x)     	__builtin_popcount(x)
#define fill(a,b)   	memset(a,b,sizeof(a))
#define mod 			1000000007
#define hell            998244353 

ll mod_pow(ll a,ll b,ll m) 
{
    ll res = 1;
    while(b)	
    {
        if(b&1) 	
        {
        	res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

ll mod_inverse(ll a) 
{
	return mod_pow(a , mod-2 , mod);
}

void solve() {
	
	int n , d;
	
	cin >> n >> d;
	
	int a[n][d];
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < d; ++j) {
			cin >> a[i][j];
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i) {
		for(int j = i+1; j < n; ++j) {
			int res = 0;
			
			for(int z = 0; z < d; ++z) {
				res += (a[i][z] - a[j][z])*(a[i][z] - a[j][z]);
			}
			
			int p = sqrt(res);
			
			if(p*p == res) {
				ans++;
			}
		}
	}
	
	cout << ans;
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
