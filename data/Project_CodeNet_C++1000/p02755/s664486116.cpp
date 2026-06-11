#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll a,b;
	cin>>a>>b;
	for(ll i=0;i<=1000000;i++){
		if(i*8/100==a&&i*10/100==b){
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}