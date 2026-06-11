#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll h;
	cin>>h;
	ll now=1;
	ll ans=0;
	while(h!=0){
		ans+=now;
		h/=2;
		now*=2;
	}
	cout <<ans;
	// your code goes here
	return 0;
}