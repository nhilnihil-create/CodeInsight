#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b;
	cin>>a>>b;
	for(ll i=1;i<=100000;i++){
		if(ll(i*0.08)==a&&ll(i*0.1)==b){
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}