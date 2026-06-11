#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	double a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);
	double ans = (a[0]+a[1])/2;
	for(int i=2; i<n; i++){
		ans = (ans+a[i])/2;
	}
	cout << ans;
	return 0;
}