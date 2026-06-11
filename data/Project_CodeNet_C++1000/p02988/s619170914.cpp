#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[22];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll ans=0;
	for(ll i=2;i<n;i++){
		if(ch[i-2]<ch[i-1]&&ch[i-1]<ch[i]){
			ans++;
		}
		if(ch[i-2]>ch[i-1]&&ch[i-1]>ch[i]){
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}