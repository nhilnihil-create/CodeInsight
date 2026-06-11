#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll N, A = 0, B = 0, C = 0;
	cin >> N;
	string S;
	cin >> S;
	ll gk = 0;
	for (ll i = 0;i < N;i++) {
		ll x = i, y = N - i;
		while (x) {
			if (x % 2)break;
			gk--;
			x /= 2;
		}
		while (y) {
			if (y % 2)break;
			gk++;
			y /= 2;
		}
		if (i == 0)gk = 0;

		if (gk == 0) {
			if (S[i] == '2') {
				B++;
			}
			else if (S[i] == '3') {
				C++;
			}
		}
		if (S[i] == '2')A++;
	}
	if (B & 1) {
		cout << 1 << endl;
	}
	else if (A) {
		cout << 0 << endl;
	}
	else if (C & 1) {
		cout << 2 << endl;
	}
	else {
		cout << 0 << endl;
	}
}