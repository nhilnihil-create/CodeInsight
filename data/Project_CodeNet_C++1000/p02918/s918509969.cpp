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
	ll g=1;
	for(ll i=1;i<n;i++){
		if(s[i-1]!=s[i]){
			g++;
		}
//		cout <<g;
	}
	ll ans=n-g;
	ll no=min(k,(g-1)/2);
	ans+=no*2;
	k-=no;
	g-=no*2;
	if(k>=1&&g>=2){
		ans++;
	}
	cout <<ans;
	// your code goes here
	return 0;
}