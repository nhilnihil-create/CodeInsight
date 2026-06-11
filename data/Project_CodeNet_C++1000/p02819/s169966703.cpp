#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll x;
	cin>>x;
	for(ll i=2;;i++){
		ll now=i;
		bool ch=true;
		for(ll j=2;j<=sqrt(i);j++){
			if(now%j==0){
				ch=false;
				break;
			}
		}
		if(ch){
			if(i>=x){
				cout << i;
				return 0;
			}
		}
	}
	// your code goes here
	return 0;
}