#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
ll ch[200010],ans[200010];
int main() {
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll now;
		cin>>now;
		ch[i]=now;
	}
	ll ANS=0;
	for(ll i=n;i>=1;i--){
		ll cnt=0;
		ll now=1;
		while(now*i<=n){
			cnt+=ans[i*now];
			now++;
		}
		if(cnt%2!=ch[i]){
			ans[i]=1;
			ANS++;
		}
	}
	cout << ANS<<endl;
	for(ll i=1;i<=n;i++){
		if(ans[i]){
			cout << i<<endl;
		}
	}
	// your code goes here
	return 0;
}