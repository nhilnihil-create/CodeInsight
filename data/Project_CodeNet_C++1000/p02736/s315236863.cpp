#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int a[1000006];

int x[1000006];

int c[4];

long long int p[2000006];

long long int MOD = 1000000007;

long long int POW(long long int a, long long int k) {
	if (k == 0) { return 1; }
	if (k == 1) { return a;}

	if (k % 2 == 1) { return (POW(a, k - 1)*a) % MOD; }
	long long int tmp;
	tmp = POW(a, k / 2);

	return (tmp*tmp) % MOD;
}

long long int INV(long long int K) {
	return POW(K, MOD - 2);
}

int C(int n, int m) {
	bool y = (n== (n | (n - m)));
	return y;
}

string s;
int main(void) {

	cin >> N;
	cin >> s;
	for (int i = 1; i <= N; i++) {
		x[i-1] = s[i - 1] - '0'-1;
	}

	for (int i = 1; i <= N; i++) {
		c[x[i-1]]++;
	}

	int ans = 0;

	if (c[1] == 0) {
		long long int num = 0;
		for (int i = 0; i <= N - 1; i++) {
			if (x[i] == 2) { num += C(N - 1, i); num %= 2; }
		}
		if (num == 1) { ans = 2; }
		else { ans = 0; }
	}
	else {
		int num = 0;
		for (int i = 0; i <= N - 1; i++) {
			//cout <<x[i]<<"  "<< C(N - 1, i) << endl;
			if (x[i] == 1) {
				num += C(N - 1, i);   num %= 2;
			}
		}
		if (num == 1) { ans = 1; }
		else { ans = 0; }
	}

	cout << ans << endl;
	

	return 0;
}