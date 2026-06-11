#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
#define _USE_MATH_DEFINES
#include <math.h>
int main() {
	ll n,m;cin>>n>>m;
	ll sum=0;
	for(ll i=0;i<m;i++){
		ll now;
		cin>>now;
		sum+=now;
	}
	if(sum<=n){
		cout << n-sum;
	}
	else{
		cout << -1;
	}
	// your code goes here
	return 0;
}