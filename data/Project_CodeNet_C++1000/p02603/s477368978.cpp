#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	int k, t, i, s, n;

	cin >> n;
	vector<int> a(n);
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	
	ll x = 1000;
	for (i = 0; i < n-1; i++){
		s = a[i];
		t = a[i + 1];

		if (t > s){
		ll k = x/s;
		x = x%s;
		x += k*t;
		}
	}

	cout << x << endl;
	return 0;
}