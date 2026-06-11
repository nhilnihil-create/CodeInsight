#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
 
int main() {
	ll a,b,c;
	cin>>a>>b>>c;
	ll ma=max({a,b,c});
	cout <<a+b+c-ma;
	// your code goes here
	return 0;
}