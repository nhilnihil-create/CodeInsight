#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	//ifstream cin (".in");
	//ofstream cout (".out")
	
	ll n;
	cin >> n;
	ll ans=0;
	
	for(ll i=2; n>1 && i*i<=n; ++i) {
		int temp=0;
		while(n%i==0) ++temp, n/=i;
		for(int j=1; ; ++j) {
			if(temp>=j) ++ans, temp-=j;
			else break;
		}
	}
	
	if(n>1) ++ans;
	
	cout << ans << '\n';
	return 0;
}
