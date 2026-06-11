#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	ll ans[100010]={};
	ll l=0;
	ll r=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='R'){
			r++;
			swap(l,r);
		}
		else{
			ans[i-1]+=l;
			ans[i]+=r;
			l=r=0;
		}
	}
	ans[s.size()-1]+=l+r;
	l=r=0;
	for(ll i=s.size()-1;i>=0;i--){
		if(s[i]=='L'){
			l++;
			swap(l,r);
		}
		else{
			ans[i]+=l;
			ans[i+1]+=r;
			l=r=0;
		}
	}
	ans[0]+=l+r;
	for(ll i=0;i<s.size();i++){
		cout<<ans[i]<<" ";
	}
	// your code goes here
	return 0;
}