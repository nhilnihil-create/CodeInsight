#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,a[300];
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(ll i=2;i<n;i++){
		if(a[i-2]<a[i-1]&&a[i-1]<a[i]){
			ans++;
		}
		else if(a[i-2]>a[i-1]&&a[i-1]>a[i]){
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}