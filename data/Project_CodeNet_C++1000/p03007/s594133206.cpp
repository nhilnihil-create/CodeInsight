#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
	lint N, sum = 0;
	cin >> N;
	vector<lint> a(N);
	for(lint i = 0; i < N; i++) cin >> a[i], sum += abs(a[i]);
	sort(a.begin(), a.end());
	if(a[0] > 0) sum -= a[0] * 2;
	if(a.back() < 0) sum += a.back() * 2;
	cout << sum << endl;
	lint x = a[0];
	for(lint i = 1; i < N - 1; i++){
		if(a[i] >= 0){
	 	  cout << x << " " << a[i] << endl;
		  x -= a[i];
		}
	}
	cout << a.back() << " " << x << endl;
	x = a.back() - x;
	for(lint i = 1; i < N - 1; i++){
		if(a[i] < 0){
			cout << x << " " << a[i] << endl;
			x -= a[i];
		}
	}
}