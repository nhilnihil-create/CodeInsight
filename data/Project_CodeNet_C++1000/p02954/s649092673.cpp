#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll ans[100010];
int main() {
	string s;
	cin>>s;
	ll cnt=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='R'){
			cnt++;
		}
		else{
			ans[i]+=cnt/2;
			ans[i-1]+=(cnt+2-1)/2;
			cnt=0;
		}
	}
	for(ll i=s.size()-1;i>=0;i--){
		if(s[i]=='L'){
			cnt++;
		}
		else{
			ans[i]+=cnt/2;
			ans[i+1]+=(cnt+2-1)/2;
			cnt=0;
		}
	}	
	for(ll i=0;i<s.size();i++){
		cout <<ans[i]<<" ";
	}
	// your code goes here
	return 0;
}