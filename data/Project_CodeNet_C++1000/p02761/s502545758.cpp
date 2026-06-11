#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll n,k;
	ll ch[3];
	cin>>n>>k;
	for(ll i=0;i<3;i++){
		ch[i]=-1;
	}
	for(ll i=0;i<k;i++){
		ll x,y;
		cin>>x>>y;
		x--;
		if(ch[x]==-1){
			ch[x]=y;
		}
		else{
			if(ch[x]!=y){
				cout << -1;
				return 0;
			}
		}
	}
	for(ll i=0;i<n;i++){
		if(i==0){
			if(ch[i]==0){
				if(n==1){
					cout << 0;
					return 0;
				}
				cout << -1;
				return 0;
			}
			else{
				if(n==1&&ch[i]==-1){
					cout << 0;
					return 0;
				}
				cout <<max(ch[i],ll(1));
			}
		}
		else{
			cout << max(ch[i],ll(0));
		}
	}
	// your code goes here
	return 0;
}