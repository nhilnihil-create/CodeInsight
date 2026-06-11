#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>ch;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		ch.push_back(now);
	}
	sort(ch.begin(),ch.end());
	long double ans=ch[0];
	for(ll i=1;i<n;i++){
		ans+=ch[i];
		ans/=2;
	}
	cout <<ans;
	return 0;
}