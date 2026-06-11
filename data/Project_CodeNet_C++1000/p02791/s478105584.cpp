#include <bits/stdc++.h>
using namespace std;
#include <math.h> 
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[200010];
	ll ma=inf;ll ans=0;
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	for(ll i=0;i<n;i++){
		ll now=ch[i];
		if(now<ma){
			ma=now;
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}