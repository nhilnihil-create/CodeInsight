#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007


int main() {
	ll n;
	cin>>n;
	ll ch[200010];
	map<ll,ll>q;
	for(ll i=0;i<n;i++){
		cin>>ch[i];
		q[ch[i]]++;
	}
	ll cnt=0;
	for(auto itr=q.begin();itr!=q.end();itr++){
		ll val=itr->second;
		cnt+=val*(val-1)/2;
	}
	for(ll i=0;i<n;i++){
		ll now=ch[i];
		ll t=q[now];
		cout << cnt-q[now]*(q[now]-1)/2+(q[now]-1)*(q[now]-2)/2<<endl;
	}
	// your code goes here
	return 0;
}