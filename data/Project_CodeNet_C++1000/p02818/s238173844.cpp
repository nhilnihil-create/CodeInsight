#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b,k;
	cin>>a>>b>>k;
	ll K=k-a;
	a=max(ll(0),a-k);
	if(K>0){
		b=max(ll(0),b-K);
	}
	cout << a<<" "<<b;
	// your code goes here
	return 0;
}