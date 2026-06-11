#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

bool ch[100010];ll ans[100010];
int main() {
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<k;i++){
		ll x;
		cin>>x;
		ch[x]=true;
	}
	ans[0]=1;
	for(ll i=0;i<=n;i++){
		ans[i+2]+=ans[i];
		ans[i+1]+=ans[i];
//		cout << ans[2]<<endl;
		if(ch[i+2]==true){
			ans[i+2]=0;
		}
		if(ch[i+1]==true){
			ans[i+1]=0;
		}
		ans[i+2]%=inf;
		ans[i+1]%=inf;
	}
	cout << ans[n];
	// your code goes here
	return 0;
}