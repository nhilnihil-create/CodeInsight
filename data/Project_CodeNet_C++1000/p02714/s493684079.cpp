#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int gcd(int a,int b) {//最大公約数の算出
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void) {
	int n;
	string s;
	cin >> n;
	cin >> s;
	ll p = 0;
	ll a = 0, b = 0, c = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			a++;
		}
		else if (s[i] == 'G') {
			b++;
		}
		else if (s[i] == 'B') {
			c++;
		}
	}
	p = a * b*c;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if ((2 * j - i) < n) {
				int k = 2 * j - i;
				if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) {
					p--;
				}
			}


		}
	}

	cout << p;
	return 0;
}