#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b,c;
	cin>>a>>b>>c;
	ll now=a-b;
	cout << max(ll(0),c-now);
	// your code goes here
	return 0;
}