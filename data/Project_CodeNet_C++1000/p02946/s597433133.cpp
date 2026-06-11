#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll k,x;
	cin>>k>>x;
	for(ll i=k-1;i>=0;i--){
		cout << x-i<<" ";
	}
	for(ll i=0;i<k-1;i++){
		cout << x+i+1<<" ";
	}
	// your code goes here
	return 0;
}