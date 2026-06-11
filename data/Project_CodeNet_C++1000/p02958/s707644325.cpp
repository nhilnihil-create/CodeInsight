#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[52];
	ll cnt=0;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		now--;
		if(now!=i){
			cnt++;
		}
	}
	if(cnt<=2){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	// your code goes here
	return 0;
}