#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	if(p==2||p==5){
		ll ans=0;
		for(ll i=0;i<n;i++){
			ll now=s[i]-'0';
			if(now%p==0){
				ans+=n-i;
			}
		}
		cout <<ans;
		return 0;
	}
	ll keta=1;
	ll ch[200010];
	for(ll i=0;i<n;i++){
		ll now=s[i]-'0';
		now*=keta;
		now%=p;
		ch[i]=now;
		keta*=10;
		keta%=p;
	}
	map<ll,ll>q;
	q[0]++;
	ll ans=0;
	ll ch2[200010]={};
	for(ll i=0;i<n;i++){
		ch2[i+1]=ch2[i]+ch[i];
		ch2[i+1]%=p;
		q[ch2[i+1]]++;
		ans+=q[ch2[i+1]]-1;
	}
	cout <<ans;
	return 0;
}