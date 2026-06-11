#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e6+5;
void solve(){
	int n,m; 
	cin>>n>>m;
	priority_queue<ll>pq; 
	for(int i=1;i<=n;i++){
		ll x; 
		cin>>x; 
		pq.push(x);
	}
	for(int i=1;i<=m;i++){
		ll x = pq.top();
		pq.pop();
		x/=2ll;
		pq.push(x);
	}
	ll ans = 0;
	while(!pq.empty()){
		ll x = pq.top();
		pq.pop();
		ans+=x;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
