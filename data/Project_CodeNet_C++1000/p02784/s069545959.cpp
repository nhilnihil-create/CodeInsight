#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll h,m;
	cin>>h>>m;
	ll cnt=0;
	for(ll i=0;i<m;i++){
		ll now;
		cin>>now;
		cnt+=now;
	}
	if(cnt>=h){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	// your code goes here
	return 0;
}