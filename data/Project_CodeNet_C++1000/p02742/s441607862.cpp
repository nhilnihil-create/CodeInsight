#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b;
	cin>>a>>b;
	if(a==1||b==1){
		cout << 1;
		return 0;
	}
	cout << (a*b+2-1)/2;
	// your code goes here
	return 0;
}