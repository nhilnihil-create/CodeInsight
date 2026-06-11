#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	ll ans[100010];
	for(ll i=0;i<n;i++){
		ans[i]=0;
		if(s[i]=='R'){
			if(i==n-1){
				continue;
			}
			else if(s[i+1]=='R'){
				ans[i]=1;
			}
		}
		else if(s[i]=='L'){
			if(i==0){
				continue;
			}
			else if(s[i-1]=='L'){
				ans[i]=1;
			}
		}
	}
	for(ll i=0;i<n-1;i++){
		if(k==0){
			break;
		}
		if(ans[i]==0&&ans[i+1]==0){
			ans[i]=1;
			ans[i+1]=1;
			k--;
		}
	}
	for(ll i=0;i<n;i++){
		if(k==0){
			break;
		}
		if(ans[i]==0){
			k--;
			ans[i]=1;
		}
	}
	ll sum=0;
	for(ll i=0;i<n;i++){
		sum+=ans[i];
	}
	cout <<min(sum,n-1);
	// your code goes here
	return 0;
}