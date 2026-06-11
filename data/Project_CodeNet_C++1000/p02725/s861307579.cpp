#include <bits/stdc++.h>
using namespace std;

int k, n, res;

int main(){
	
	cin >> k >> n;
	int a[n], a2[n], r[n];
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		a2[i] = min(a[i], k-a[i]);
	}
	
	sort(a, a+n);
	
	for(int i = 0; i < n-1; i ++){
		r[i] = min( (a2[i]+a2[i+1]), (a[i+1] - a[i]));
	}
	
	r[n-1] = min( (a2[0]+a2[n-1]), (a[n-1] - a[0]));
	
	sort(r, r+n);
	
	for(int i = 0; i < n-1; i ++){
		res += r[i];
	}
	
	cout << res;
	
	return 0;
}
