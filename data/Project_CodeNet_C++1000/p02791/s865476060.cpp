#include <bits/stdc++.h>
using namespace std;
#include <math.h> 
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,ch[200010];
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll ans=1;
	ll ma=ch[0];
	for(ll i=1;i<n;i++){
		ll now=ch[i];
		if(now<=ma){
			ans++;
			ma=now;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}