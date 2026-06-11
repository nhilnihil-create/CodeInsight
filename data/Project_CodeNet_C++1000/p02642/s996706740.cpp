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
typedef unsigned long ul;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

const int MX = 1e6;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<bool> good(MX+1, true);
	vi v(n), cnt(MX+1);
	
	for(int i=0; i<n; ++i) {
		cin >> v[i];
		++cnt[v[i]];
	}
	
	
	for(int i=1; i<=MX; ++i) {
		if(cnt[i]>0) {
			for(int j=2*i; j<=MX; j+=i) good[j]=false;
		}
	}
	
	int ans=0;
	
	for(auto x: v) {
		if(cnt[x]==1 && good[x]) ++ans;
	}
	
	cout << ans << "\n";
	
	return 0;
}
