#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,k;
	cin>>n>>k;
	ll now=n%k;
	cout << min(k-now,now);
	return 0;
}