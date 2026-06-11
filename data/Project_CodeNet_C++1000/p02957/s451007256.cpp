#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b;
	cin>>a>>b;
	ll l=a*a-b*b;
	ll r=2*a-2*b;
	if(l%r==0){
		cout << l/r;
	}
	else{
		cout << "IMPOSSIBLE";
	}
	// your code goes here
	return 0;
}