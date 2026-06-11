#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[200010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
		ch[i]--;
	}
	ll now=0;
	ll ans=0;
	for(ll i=0;i<n;i++){
		if(ch[i]!=now){
			ans++;
		}
		else{
			now++;
		}
	}
	if(ans==n){
		cout << -1;
		return 0;
	}
	cout <<ans;
	// your code goes here
	return 0;
}