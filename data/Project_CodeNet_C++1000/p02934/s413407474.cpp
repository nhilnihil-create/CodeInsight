#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	long double cnt=0.0;
	for(ll i=0;i<n;i++){
		long double now;
		cin>>now;
		cnt+=1/now;
	}
	cnt=1/cnt;
	printf("%.9Lf",cnt);
	// your code goes here
	return 0;
}