#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
int main() {
	ll n;
	cin>>n;
	vector<ll>q;
	vector<ll>p;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			q.push_back(i);
			q.push_back(n/i);
		}
	}
	for(ll i=1;i*i<=n-1;i++){
		if((n-1)%i==0){
			p.push_back(i);
			p.push_back((n-1)/i);
		}
	}	
	set<ll>ans;
	for(ll i=0;i<q.size();i++){
		ll k=q[i];
		if(k==1){
			continue;
		}
		ll now=n;
		while(now%k==0){
			now/=k;
		}
		now%=k;
		if(now==1){
			ans.insert(k);
			//cout <<k<<endl;
		}
	}
	for(ll i=0;i<p.size();i++){
		ll k=p[i];
		if(k==1){
			continue;
		}
		if((n-1)%k==0){
			ans.insert(k);
		}
	}
	cout << ans.size();
	// your code goes here
	return 0;
}