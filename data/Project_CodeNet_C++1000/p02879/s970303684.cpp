#include <bits/stdc++.h>
using namespace std;
#include <cmath>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b;
	cin>>a>>b;
	if(a>=10||b>=10){
		cout << -1;
	}
	else{
		cout << a*b;
	}
	// your code goes here
	return 0;
}