#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,m,a[101];
	cin>>n>>m;
	ll cnt=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	ll sum=0;
	for(ll i=0;i<n;i++){
		if(a[i]*4*m>=cnt){
			sum++;
		}
	}
	if(sum>=m){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	// your code goes here
	return 0;
}