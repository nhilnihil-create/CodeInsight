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
	int n , k;
	
	cin >> n >> k;
	
	int t = n-2;
	
	int mx = t + (t*(t-1))/2; 
	
	if(k > mx) {
		cout << -1;
		return;
	}
	
	vector<pair<int,int>> ans;
	
	ans.pb({1,2});
	
	vector<int> dis2;
	
	dis2.pb(1);
	
	int tot = 0;
	int flg = 0;
	
	for(int i = 3; i <= n; ++i) {
		
		if(flg) {
			ans.pb({2,i});
			for(auto u : dis2) {
				ans.pb({i , u});
			}
			dis2.pb(i);
			continue;
		}
		if(tot + dis2.size() <= k) {
			ans.pb({2 , i});
			tot += dis2.size();
		}
		else {
			ans.pb({2 , i});
			
			int tm = tot + dis2.size() - k;
			
			for(int j = 0; j < tm; ++j) {
				ans.pb({i , dis2[j]});
			}
			
			//cout << i << " " << tm << endl;
			
			tot += dis2.size();
			
			flg = 1;
		}
		
		dis2.pb(i);
	}
	
	cout << ans.size() << endl;
	
	for(auto u : ans) {
		cout << u.F << " " << u.S << endl;
	}
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
