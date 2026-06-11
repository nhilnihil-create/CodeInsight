#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dep(ll a, ll b){
	if(b==0){
		return a;
	}
	return dep(b,a%b);
}
int main() {
	ll n;
	cin>>n;
	ll ch[200010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll ans=0;
	ll now=1;
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
	return 0;
}