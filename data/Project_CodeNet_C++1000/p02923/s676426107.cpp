#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[100010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll ans=0;ll cnt=0;
	ll now=ch[0];
	for(ll i=1;i<n;i++){
		if(ch[i]<=now){
			cnt++;
			now=ch[i];
		}
		else{
			now=ch[i];
			ans=max(ans,cnt);
			cnt=0;
		}
	}
	cout << max(ans,cnt);
	// your code goes here
	return 0;
}