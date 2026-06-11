#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using ll = long long;

int main(void){
	int n=0;
	cin >> n;
	
	vector<ll> a(n,0),b(n,0);
	rep(i,n){
		cin >> a[i] >> b[i];
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int aa=0,bb=0;
	int ans = 0;
	
	if((n%2)==1){
		aa = a[(n-1)/2];
		bb = b[(n-1)/2];
		ans = (bb - aa) + 1;
	} else {
		aa = a[n/2]+a[n/2-1];
		bb = b[n/2]+b[n/2-1];
		ans = bb - aa + 1;
	}
	cout << ans << endl;
}

