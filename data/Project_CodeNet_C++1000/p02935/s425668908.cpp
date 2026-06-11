#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
	ll n; cin>>n;
	priority_queue<double,vector<double>,greater<double>> pq;
	ll a[n]; for(ll i=0;i<n;i++) cin>>a[i],pq.push((double)a[i]);
	ll ans=0;
	while(pq.size()>1){
		auto x=pq.top(); pq.pop();
		auto y=pq.top(); pq.pop();
		pq.push((x+y)/2.0);
	}
	cout<<fixed<<setprecision(12)<<pq.top();
}
