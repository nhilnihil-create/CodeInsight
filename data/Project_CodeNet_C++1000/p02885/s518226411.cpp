#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b;
	cin>>a>>b;
	if(a>b*2){
		cout << a-b*2;
	}
	else{
		cout << 0;
	}
	// your code goes here
	return 0;
}