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

void solve() 
{
	int n , m;
	
	cin >> n >> m;
	
	string s[n];
	
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	
	int left[n][m] {};
	int right[n][m] {};
	int up[n][m] {};
	int down[n][m] {};
	
	for(int i = 0; i < n; ++i) {
		int cnt = 0;
		for(int j = 0; j < m; ++j) {
			if(s[i][j] == '.') {
				cnt++;
				left[i][j] = cnt;
			}
			else {
				cnt = 0;
			}
		}
	}
	
	for(int i = 0; i < n; ++i) {
		int cnt = 0;
		for(int j = m-1; j >= 0; --j) {
			if(s[i][j] == '.') {
				cnt++;
				right[i][j] = cnt;
			}
			else {
				cnt = 0;
			}
		}
	}
	
	for(int i = 0; i < m; ++i) {
		int cnt = 0;
		for(int j = 0; j < n; ++j) {
			if(s[j][i] == '.') {
				cnt++;
				down[j][i] = cnt;
			}
			else {
				cnt = 0;
			}
		}
	}
	
	for(int i = 0; i < m; ++i) {
		int cnt = 0;
		for(int j = n-1; j >= 0; --j) {
			if(s[j][i] == '.') {
				cnt++;
				up[j][i] = cnt;
			}
			else {
				cnt = 0;
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(s[i][j] == '.') {
				ans = max(ans , left[i][j] + up[i][j] + right[i][j] + down[i][j] - 3);
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
