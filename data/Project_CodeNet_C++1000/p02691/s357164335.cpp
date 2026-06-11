#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
 

int main() {
	ll n;
	cin>>n;
	map<ll,ll>ch;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;		
		if(i!=0){
		ans+=ch[i+1-x];
		}

		ch[x+(i+1)]++;
	}
	cout <<ans;
	// your code goes here
	return 0;
}