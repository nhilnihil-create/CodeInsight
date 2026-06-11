#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define A 5e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	string s; cin >> s;
	int L = s.size(), le = 0, ri = 0;
	ll ans = 0;
	vector<int> a(L + 1, -1);
	for (int i = 0; i < L; i++) {
		if (s[i] == '<') {
			for (int j = 0; j <= ri; j++) {
				a[i - j] = max(a[i-j],le + j);
			}
			le++;
			ri = 0;
			if (i == L - 1)a[L] = a[L - 1] + 1;
		}
		else {
			a[i] = le;
			ri++;
			le = 0;
			if (i == L - 1) {
				for (int j = 0; j <= ri; j++) {
					a[L - j] = le + j;
				}
			}
		}


	}
	for (int i = 0; i <= L; i++) {
		//cout << a[i] << " ";
		ans += a[i];
	}
	//cout << endl;
	cout << ans << endl;
}