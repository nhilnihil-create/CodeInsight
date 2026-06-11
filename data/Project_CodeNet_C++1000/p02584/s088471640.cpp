#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int64_t n , k , d;
	cin >> n >> k >> d;
	n = abs(n);
	if(n/d >= k){
		n = n - d*k;
		cout << n;
		return 0;
	}
	int64_t x = n/d;
	
	n = n - x *d;
	k = k - x; // Hope's are left

	if(k % 2 == 0){
		cout << n;
		return 0;
	}
	else{
		cout << min(n + d  , abs(n-d));
	}
	return 0;
}

