#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;
// typedef long long int 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
// typedef pair<ll,ll> pll;
const int modi = 1e9+7;

void solve(){
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int dp[n+1]; // number of jumps to reach i
	memset(dp,0,sizeof(dp));
	set<int> last_reach;
	last_reach.insert(n);
	for(int i =n-1;i>=0;i--){
		// cout << i << endl;/
		if(s[i]=='1')
			dp[i] = modi;
		else{
			if(i+m<*last_reach.begin()){
				dp[i] = modi;
				continue;
			}
			int to = *--last_reach.upper_bound(i+m);
			// cout << " to " << to << endl;
			if(to>i+m)
				dp[i] = modi;
			else{
				if(dp[to]==modi)dp[i] = modi;
				else{
					dp[i] = 1 + dp[to];
					last_reach.insert(i);
				}
			}
		}
	}
	if(dp[0]!=modi){
		int jumps = dp[0];
		// cout << jumps << endl;
		// int i =1;
		int last = 0;
		vector<int> places;
		for(int i =1;i<=n;i++){
			if(dp[i]==jumps-1){
				places.pb(i-last);
				last = i;
				jumps--;
			}
		}

		for(auto e:places){
			cout << e << " ";
		}
		cout << endl;
	}	
	else{
		cout << -1 << endl;
	}
 }
int main(){
	fast;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	// int t;cin >> t;while(t--)
		solve();
}
