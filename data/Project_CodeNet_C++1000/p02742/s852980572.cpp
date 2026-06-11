#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll h,w;
	cin>>h>>w;
	if(h==1||w==1){
		cout << 1;
	}
	else{
		cout << (h*w+1)/2;
	}
	// your code goes here
	return 0;
}