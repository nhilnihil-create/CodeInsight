#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll h,m;
	cin>>h>>m;
	ll sum=0;
	for(ll i=0;i<m;i++){
		ll x;
		cin>>x;
		sum+=x;
	}
	if(sum>=h){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	// your code goes here
	return 0;
}