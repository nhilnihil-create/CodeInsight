#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ll long long
#define db double
#define el "\n"
#define ld long double
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
#define tr(ds, it) for(auto it=ds.begin(); it!=ds.end(); it++)
#define rtr(ds, it) for(auto it=ds.rbegin(); it!=ds.rend(); it--)
#define all(ds) ds.begin(), ds.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef priority_queue <int> pq;
typedef vector< long long > vi;
typedef pair<long long, long long> ii;
#define o_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 


const ll mod = 1000000007;
ll po(ll x, ll n ){ 
	ll ans=1;
     while(n>0){
     	if(n&1) ans=(ans*x)%mod;
     	x=(x*x)%mod;
     	n/=2;
     }
     return ans;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r" , stdin);
	// freopen("output.txt", "w" , stdout);
	// #endif
	int T=1;
	//cin >> T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		ll a[n];
		rep(i,n) cin>>a[i];
		ll p[n]={0};
		p[0]=a[0];
		rep_a(i,1,n) p[i]=p[i-1]+a[i];
		ll d[n];
		rep(i,n) d[i]=p[i]-i-1;
		ll r[n+1];
		r[0]=0;
		rep(i,n) r[i+1]=d[i]%k;
		// rep(i,n+1) cout<<r[i]<<" ";
		// cout<<el;
		map<ll,ll>m;
		ll ans=0;
		rep(i,min(k,n+1)){ 
			m[r[i]]++;
		}
		tr(m,h){
			ans+=((h->ss)*((h->ss)-1))/2;
		}
		rep_a(i,k,n+1){
			m[r[i-k]]--;
			if(m[r[i-k]]==0) m.erase(r[i-k]);
			if(m.find(r[i])!=m.end()) ans+=m[r[i]];
			m[r[i]]++;
		}
		cout<<ans<<el;
	}

	return 0;
}