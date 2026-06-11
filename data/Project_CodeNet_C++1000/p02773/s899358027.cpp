#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	map<string,ll>q;
	ll ans=0;
	for(ll i=0;i<n;i++){
		string t;
		cin>>t;
		q[t]++;
		ans=max(q[t],ans);
	}
	for(auto itr=q.begin();itr!=q.end();itr++){
		ll num=itr->second;
		if(num==ans){
			cout << itr->first<<endl;
		}
	}
	// your code goes here
	return 0;
}