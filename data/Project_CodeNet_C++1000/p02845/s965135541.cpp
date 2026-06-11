#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[3];
int main() {
	ll n;
	cin>>n;
	ll ans=1;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		ll cnt=0;
		bool ch=true;
		for(ll i=0;i<3;i++){
			if(a[i]==now){
				cnt++;
				if(ch){
					ch=false;
					a[i]++;
				}
			}
		}
		ans*=cnt;
		ans%=inf;
	}
	cout <<ans;
	// your code goes here
	return 0;
}