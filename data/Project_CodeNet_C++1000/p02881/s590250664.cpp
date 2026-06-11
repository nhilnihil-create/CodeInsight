#include <bits/stdc++.h>
using namespace std;
#include <cmath>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ans=1;
	for(ll i=1;i<=sqrt(n);i++){
		if(n%i==0){
			ans=max(i,ans);
		}
	}
	ll ans2=n/ans;
	cout <<ans+ans2-2;
	// your code goes here
	return 0;
}