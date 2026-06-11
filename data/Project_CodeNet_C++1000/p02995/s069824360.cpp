#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main() {
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll lcm=c/gcd(max(c,d),min(c,d))*d;
	ll l=(a-1)-((a-1)/c+(a-1)/d-(a-1)/lcm);
	ll r=b-(b/c+b/d-b/lcm);
	cout << r-l;
	// your code goes here
	return 0;
}