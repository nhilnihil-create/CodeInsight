#include<bits/stdc++.h>
#define rep(i, x) for(int i = 0; i < x; i++)
using namespace std;

std::vector<int> z_algorithm(std::string s) {
	int n = s.size();
	std::vector<int> z(n);
	z[0] = n;
	int l = 0, r = 0;
	for(int i = 1; i < n; i++) {
		if (r < i) {
			l = i; r = i;
			for(int j = 0; r < n; j++, r++) {
				if (s[j] != s[r]) break;
			}
			z[i] = r - l;
		} else {
			int p = i - l, q = r - i;
			if (z[p] != q) {
				z[i] = std::min(z[p], q);
			} else {
				l = i;
				for(int j = q; r < n; j++, r++) {
					if (s[j] != s[r]) break;
				}
				z[i] = r - l;
			}
		}
	}
	return z;
}


int main() {
	int n;
	string s;
	cin >> n >> s;
	int mx = 0;
	rep(i, n) {
		string st = s.substr(i);
		auto z = z_algorithm(st);
		for(int j = 1; j < n - i; j++) {
			mx = max(mx, min(z[j], j));
		}
	}
	cout << mx << endl;
}

