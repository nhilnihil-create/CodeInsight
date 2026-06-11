#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
#define _USE_MATH_DEFINES
#include <math.h>
int main() {
	ll n,k;
	cin>>n>>k;
	ll u[200010]={},d[200010]={};
	u[0]=0;
	d[0]=n;
	for(ll i=1;i<=n;i++){
		u[i]+=i+u[i-1];
		d[i]+=n-i+d[i-1];
	}
	ll sum=0;
	for(ll i=k-1;i<=n;i++){
	//	cout << u[i]<<" "<<d[i]<<endl; 
		sum+=d[i]-u[i]+1;
		sum%=inf;
	}
	cout <<sum;
	// your code goes here
	return 0;
}