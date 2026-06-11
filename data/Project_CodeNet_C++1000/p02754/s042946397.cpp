#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll n,a,b;
	cin>>n>>a>>b;
	cout << n/(a+b)*a+min(n%(a+b),a);
	// your code goes here
	return 0;
}