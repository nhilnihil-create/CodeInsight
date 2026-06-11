#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	long double x[10],y[10];
	for(ll i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	long double kai=1;
	for(ll i=1;i<=n-1;i++){
		kai*=i;
	}
	long double cnt=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			cnt+=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))*2*kai;
		}
	}
	printf("%.9Lf",cnt/(kai*n));
	return 0;
}