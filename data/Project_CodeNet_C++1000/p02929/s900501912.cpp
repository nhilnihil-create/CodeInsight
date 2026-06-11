#include <iostream>
#include <string>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int mod = 1000000007;
int n;
string s;
bool isRight[200000];

signed main() {
	int i;
	
	cin >> n >> s;
	
	if (s[0] == 'W') { cout << 0 << endl; return 0; }
	
	isRight[0] = false;
	for (i = 1; i < s.length(); i++) {
		if (s[i - 1] != s[i]) {
			isRight[i] = isRight[i - 1];
		}
		else {
			isRight[i] = !isRight[i - 1];
		}
	}
	
	int left = 0;
	int ans = 1;
	for (i = 0; i < s.length(); i++) {
		if (isRight[i]) {
			ans *= left;
			ans %= mod;
			left--;
		}
		else {
			left++;
		}
	}
	if (left != 0) {
		cout << 0 << endl;
		return 0;
	}
	
	int fact = 1;
	for (i = 1; i <= n; i++) {
		fact = fact * i;
		fact %= mod;
	}
	cout << ans * fact % mod << endl;
	return 0;
}