#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n;
	cin>>n;
	ll a[1000];
	for(ll i=0;i<1000;i++){
		a[i]=pow(i,5);
	}
	for(ll i=0;i<1000;i++){
		ll now=a[i];
		now-=n;
		bool mi=false;
		if(now<0){
			now=abs(now);
			mi=true;
		}
		for(ll j=0;j<1000;j++){
			if(now==a[j]){
				cout << i<<" ";
				if(mi==true){
					cout << j*-1;
				}
				else{
					cout <<j;
				}
				return 0;
			}
		}
	}
	// your code goes here
	return 0;
}