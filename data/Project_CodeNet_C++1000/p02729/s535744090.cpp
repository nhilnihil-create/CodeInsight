#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dep(ll now){
	return now*(now-1)/2;
}
int main() {
	ll a,b;
	cin>>a>>b;
	cout << dep(a)+dep(b);
	// your code goes here
	return 0;
}