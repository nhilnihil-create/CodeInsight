#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
bool ch[200];
int main() {
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<k;i++){
		ll now;
		cin>>now;
		for(ll j=0;j<now;j++){
			ll x;
			cin>>x;
			x--;
			ch[x]=true;
		}
	}
	ll cnt=0;
	for(ll i=0;i<n;i++){
		if(ch[i]==0){
			cnt++;
		}
	}
	cout <<cnt;
	// your code goes here
	return 0;
}