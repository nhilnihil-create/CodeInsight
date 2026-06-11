#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll l,r;
	cin>>l>>r;
	map<ll,ll>ch;
	for(ll i=2;i<=1000000;i++){
		if(l%i==0){
			ch[i]++;
		}
		while(l%i==0){
			l/=i;
		}
	}
	if(l!=1){
	ch[l]++;
	}
	for(ll i=2;i<=1000000;i++){
		if(r%i==0){
			ch[i]++;
		}
		while(r%i==0){
			r/=i;
		}
	}
	if(r!=1){
	ch[r]++;
	}
	ll ans=1;
	for(auto itr=ch.begin();itr!=ch.end();itr++){
		ans+=(itr->second)/2;
	}
	cout <<ans;
	// your code goes here
	return 0;
}