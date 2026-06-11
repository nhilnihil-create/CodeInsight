#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1LL<<62

int main() {
	ll n,d;
	cin>>n>>d;
	ll ch[12][12];
	for(ll i=0;i<n;i++){
		for(ll j=0;j<d;j++){
			cin>>ch[i][j];
		}
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			long double cnt=0;
			for(ll k=0;k<d;k++){
				cnt+=pow(ch[i][k]-ch[j][k],2);
			}
			long double now=cnt;
			for(ll k=0;k<=400;k++){
				if(now==k*k){
					ans++;
					break;
				}
			}
		}
	}
	cout <<ans;
	return 0;
}