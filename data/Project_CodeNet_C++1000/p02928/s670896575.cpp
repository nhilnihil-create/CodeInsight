#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define int ll


main(){
	int n,k;
	int a[2001];

	ll mod = 1e9+7;

	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i];


	int cnt = 0ll;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) cnt++;
		}
	}
	int cnt2 = 0ll;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]) cnt2++;
		}
	}
	int ans;
	if(k%2==0) ans = (k+1)*(k/2) % mod;
	else ans = ((k+1)/2)*k % mod;
	ans = ans * cnt % mod;

	int ans2;
	if(k%2==0) ans2 = (k-1)*(k/2) % mod;
	else ans2 = ((k-1)/2)*k % mod;
	ans2 = ans2 * cnt2 % mod;

	cout << (ans+ans2)%mod << endl;

	return 0;
}
