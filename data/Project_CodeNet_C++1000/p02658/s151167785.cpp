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
	
	int n; 
	cin >> n;
	vl v(n);
	bool hasZero=false;
	for(int i=0; i<n; ++i) {
		cin >> v[i];
		if(v[i]==0) hasZero=true;
	}
	
	if(hasZero) cout << "0\n";
	else {
		
		ll ans=1;
		for(int i=0; i<n; ++i) {
			if(ll(1e18)/v[i]>=ans) ans*=v[i];
			else {
				cout << "-1\n";
				return 0;
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
