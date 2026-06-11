#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<800000;i++){
		if(ll(i*1.08)==n){
			cout <<i;
			return 0;
		}
	}
	cout << ":(";
	// your code goes here
	return 0;
}