#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll cnt[100010];
int main() {
	ll n,k;
	cin>>n>>k;
	ll r,s,p;
	cin>>r>>s>>p;
	string t;
	cin>>t;
	for(ll i=0;i<n;i++){
		char now=t[i];
		if(i-k>=0){
			if(cnt[i-k]!=0&&t[i-k]==now){
			continue;
			}
		}
		if(now=='r'){
			cnt[i]=p;
		}
		else if(now=='s'){
			cnt[i]=r;
		}
		else{
			cnt[i]=s;
		}
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans+=cnt[i];
	}
	cout <<ans;
	// your code goes here
	return 0;
}