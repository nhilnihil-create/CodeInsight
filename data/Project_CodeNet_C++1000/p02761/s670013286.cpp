#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,m;
	cin>>n>>m;
	ll cnt=0;
	ll cnt1=0;
	if(n==1){
		cnt=9;
		cnt1=0;
	}
	else if(n==2){
		cnt=99;
		cnt1=10;
	}
	else{
		cnt=999;
		cnt1=100;
	}
	ll s[6],c[6];
	for(ll i=0;i<m;i++){
		cin>>s[i]>>c[i];
		s[i]--;
		if(s[i]==0&&c[i]==0&&n!=1){
			cout<< -1;
			return 0;
		}
		s[i]+=3-n;
	}
	for(ll j=cnt1;j<=cnt;j++){
		ll ch[3];
		ll now=j;
		for(ll i=0;i<3;i++){
			ch[2-i]=now%10;
			now/=10;
		}
		bool ans=true;
		for(ll i=0;i<m;i++){
			if(ch[s[i]]!=c[i]){
				ans=false;
			}
		}
		if(ans){
			cout << j;
			return 0;
		}
	}
	cout << -1;
	// your code goes here
	return 0;
}