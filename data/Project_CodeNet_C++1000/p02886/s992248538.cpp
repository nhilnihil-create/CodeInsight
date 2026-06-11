#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 10000000007

int main() {
	ll n;
	cin>>n;
	ll ans=0;
	ll ch[52];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			ans+=ch[i]*ch[j];
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}