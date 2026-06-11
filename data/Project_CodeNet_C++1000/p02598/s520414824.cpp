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

int n,k;
vi a;

bool valid(int mx) {
 
	ll cnt=0;
 
	for(int i=0; i<n && cnt<=n+k; ++i) {
		cnt+=ceil(a[i]/double(mx));
	}
 
	return cnt<=n+k;
 
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
 
	cin>>n>>k;
	int mx=INT_MIN;
	a.resize(n);
	for(int&q : a) cin>>q, mx=max(mx, q);

	if(k==0) {
		cout<<mx<<"\n";
		return 0;
	}

	int ans=0;
	
	for(int k=mx-1; k>=1; k/=2)
		while(!valid(ans+k))
			ans+=k;
 
	cout<<ans+1<<"\n";
 
	return 0;
}

