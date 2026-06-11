#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dep(ll a, ll b){
	if(b==0){
		return a;
	}
	return dep(b,a%b);
}
int main() {
	ll a,b;
	cin>>a>>b;
	ll gcd= dep(max(a,b),min(a,b));
	cout << a*b/gcd;
	// your code goes here
	return 0;
}