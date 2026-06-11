

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF ll(1e18)
#define MOD 998244353
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define MAXN 1000000007
 
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin>>n;
	ll arr[n+1];
	ll brr[n];

	for (ll i=0;i<n+1;i++) {
		cin>>arr[i];
	}
	for (ll i=0;i<n;i++) {
		cin>>brr[i];
	}
	ll counter=0;
	for (ll i=0;i<n;i++) {
		counter+=min(brr[i],(arr[i]+arr[i+1]));
		if (min(brr[i],(arr[i]+arr[i+1]))==brr[i]) {
			if (arr[i]<brr[i]) {
				arr[i+1]-=(brr[i]-arr[i]);
			}
		}
		else {
			arr[i+1]=0;
		}
	}
	cout<<counter;
}
