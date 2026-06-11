#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b;
	cin>>a>>b;
	for(ll i=1;i<=1000000;i++){
		ll now=i;
		if(now*8/100==a&&now*10/100==b){
			cout << now;
			return 0;
		}
	}
	cout<<-1;
	// your code goes here
	return 0;
}