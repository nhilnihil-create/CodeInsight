#include <bits/stdc++.h>
using namespace std;

const int mod = 1000*1000*1000 + 7;

#define MAXN 200*1000 + 5

int fact[MAXN];

int mul(int a, int b) {
	return (1LL * a * b) % mod;
}

void add_self(int& a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	fact[0] = 1;
	for(int i = 1; i < MAXN; i++) {
		fact[i] = mul(i, fact[i-1]);
	}
	
	int n;
	string s;
	cin >> n >> s;
	n *= 2;
	vector<int> arr(n);
	if(s[0] == 'W') {
		cout << 0 << endl;
		return 0;
	}
	
	arr[0] = 1;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i-1]) {
			arr[i] = 1 ^ arr[i-1];
		} else {
			arr[i] = arr[i-1];
		}
		
	}

	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i]) cnt++;
		else cnt--;
		if(cnt < 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	
	if(cnt > 0) {
		cout << 0 << endl;
		return 0;
	}
	
	int ans = 1;
	int L = 0, R = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i]) {
			L++;
		} else {
			ans = mul(ans, L - R);
			R++;
		}
	}
	
	ans = mul(ans, fact[n/2]);
	cout << ans << endl;
}
