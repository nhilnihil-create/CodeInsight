#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll cnt=(n-1)*(n-2)/2;
	if(cnt<k){
		cout << -1;
		return 0;
	}
	cnt=cnt-k;
//	cout <<cnt<<endl;
	cout << n-1+cnt<<endl;
	for(ll i=0;i<n-1;i++){
		cout << 1<<" "<<i+2<<endl;
	}
	for(ll i=2;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(cnt==0){
				return 0;
			}
			cout << i<<" "<<j<<endl;
			cnt--;
		//	cout <<cnt<<endl;
		}
	}
	// your code goes here
	return 0;
}