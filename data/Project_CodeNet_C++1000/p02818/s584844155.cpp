#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll n,a,b;
	cin>>a>>b>>n;
	ll k=min(n,a);
	if(n>k){
		a=0;
		n-=k;
		b=max(ll(0),b-n);
	}
	else{
		a-=n;
	}
	cout << a<<" "<<b;
	// your code goes here
	return 0;
}