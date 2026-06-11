#include <bits/stdc++.h>
using namespace std;
 
vector<long long> Gauss(vector<long long> a) {
	sort(a.begin(), a.end());
	for (int i = 59; i >= 0; i--) {
		int pos = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] < (1LL << (i + 1))) { pos = j; }
		}
		for (int j = pos - 1; j >= 0; j--) {
			if (a[j] >= (1LL << i)) a[j] ^= a[pos];
		}
		sort(a.begin(), a.end());
	}
	vector<long long> b = a;
	b.erase(unique(b.begin(), b.end()), b.end());
	return b;
}
 
int main() {

	long long N, e = 0; cin >> N;
	vector<long long> a(N, 0);
	for (int i = 0; i < N; i++) { cin >> a[i]; e ^= a[i]; }
 
	vector<long long> F;
	for (int i = 0; i < 60; i++) { if ((e & (1LL << i)) != 0) F.push_back(i); }
	for (int i = 0; i < 60; i++) { if ((e & (1LL << i)) == 0) F.push_back(i); }
 
	for (int i = 0; i < N; i++) {
		long long r = 0;
		for (int j = 0; j < 60; j++) { if ((a[i] & (1LL << F[j])) != 0) r += (1LL << j); }
		a[i] = r;
	}
 
	vector<long long> b = Gauss(a);
	long long c = 0;
	for (int i = b.size() - 1; i >= 0; i--) {
		c = max(c, c^b[i]);
	}
 
	long long ans = 0;
	for (int i = 0; i < 60; i++) {
		if ((e & (1LL << F[i])) != 0) {
			ans += (1LL << F[i]);
		}
		else {
			if ((c & (1LL << i)) != 0) ans += (2LL << F[i]);
		}
	}
	cout << ans << endl;
	return 0;
}