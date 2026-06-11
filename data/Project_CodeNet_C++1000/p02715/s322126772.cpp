#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define ll	long long
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ios	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define hell 1000000007
#define PI 3.141592653589793

ll x_power_y (int x, int y) {
	ll ans = 1ll;
	if (x == 1) return ans;
	while (y > 0) {
		if (y&1) {
			ans = (ans*x)%hell;
		}
		y>>=1;
		x = (1ll*x*x)%hell;
	}
	//ans %= hell;
	return ans;
}

int main() 
{	ios;
	int t = 1;
	//cin>>t;
	while (t--) {
		int n, k;
		cin>>n>>k;
		ll dp[k+1];
		for (int h = k; h >= 1; --h) {
			int base = k/h;
			dp[h] = x_power_y(base, n);
			for (int mul = 2; h*mul <= k; mul++) {
				dp[h] = (dp[h] - dp[h*mul])%hell;
			}
		}
		ll sum = 0;
		for (int i = 1; i <= k; i++) {
			sum = (sum + i*dp[i])%hell;
		}
		cout<<sum;
		cout<<"\n";
	}
    return 0; 
} 
