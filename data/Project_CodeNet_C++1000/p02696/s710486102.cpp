#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll a,b,n;
	cin>>a>>b>>n;
	ll ma=n/b;
	ll l=(a*n)/b-a*(n/b);
//	cout <<l<<endl;
	if(ma!=0){
		n=ma*b-1;
	}
	ll r=(a*n)/b-a*(n/b);
	cout <<max(l,r);
	// your code goes here
	return 0;
}