#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
	string S;
	cin >> S;
	ll K;
	cin >> K;

	auto count = [&](string str) {
		ll i = 0;
		ll size = str.size();
		ll count = 0;
		while (i < size) {
			ll j = i;
			ll len = 1;
			while (str[j] == str[j+1] && j < size-1) {
				len++;
				j++;
			}
			count += len / 2;
			i += len;
		}
		return count;
	};

	ll c = count(S);
	ll dc = count(S+S) - c;
	ll tc = count(S+S+S) - dc - c;

	if (c == dc)
		cout << c * K << endl;
	else if (c != dc && dc == tc) {
		cout << c + dc*(K-1) << endl;
	} else if (c != dc && dc != tc) {
		if (K % 2 == 0)
			cout << c*(K/2) + dc*(K/2) << endl;
		else
			cout << c*((K+1)/2) + dc*(K/2) << endl;
	}
}