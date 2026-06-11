#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b;
	cin>>a>>b;
	ll l=b-a+1;
	ll r=b+a-1;
	for(ll i=l;i<=r;i++){
		cout << i<<" ";
	}
	// your code goes here
	return 0;
}