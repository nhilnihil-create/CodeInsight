#include <bits/stdc++.h>
using namespace std;

const int mod = 1000*1000*1000 + 7;

int mul(int a, int b) {
	return (1LL * a * b) % mod;
}

int mpow(int a, int n) {
	if(n == 0) return 1;
	int x = mpow(a, n/2);
	x = mul(x, x);
	if(n % 2) x = mul(a, x);
	return x;
}

void add_self(int& a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}

void sub_self(int& a, int b) {
	a -= b;
	if(a < 0) a += mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int& x : arr) cin >> x;
	
	int ans = 0;
	
	vector<int> less(n), less_left(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(arr[j] < arr[i]) {
				less[i]++;
				if(j < i) less_left[i]++;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		int sum = mul(k, k+1);
		sum = mul(sum, mpow(2, mod-2));
		add_self(ans, mul(sum, less[i]));
		sub_self(ans, mul(k, less_left[i]));
	}
	
	cout << ans << endl;
}
