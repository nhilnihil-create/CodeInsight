#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,a,b;
	cin>>n>>a>>b;
	ll sum=a+b;
	ll ans=n/sum*a;
	ll sum2=n%sum;
	ans+=min(a,sum2);
	cout <<ans;
	// your code goes here
	return 0;
}