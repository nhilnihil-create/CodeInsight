#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<iomanip>
#include<math.h>
long long int C(int n, int k);
long long modpow(long long a, long long n, long long mod);
long long modinv(long long a, long long mod);

using namespace std;
int main() {

	//D

	long long int x, y;
	cin >> x >> y;
	if ((x + y) % 3 == 0) {
		if ((x >= (x + y) / 3) && (y >= (x + y) / 3)) {
			cout << C((x + y) / 3, x - (x + y) / 3) << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	else {
		cout << 0 << endl;
	}

	return 0;

	//C
	/*int n;
	cin >> n;
	long double x[8], y[8];
	int i;
	for (i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	long double dis[8][8];
	long double discounter = 0;
	int j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			dis[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			dis[i][j] = sqrt(dis[i][j]);
			discounter = discounter + dis[i][j];
		}
	}
	discounter = discounter / n;
	cout << fixed;
	cout << setprecision(10);
	cout << discounter << endl;
	return 0;
	*/


	/*
	vector<int> nums(n);
	iota(nums.begin(), nums.end(), 0);

	long double avepath = 0;
	do {
		for (i = 0; i < n - 1; i++) {
			avepath = avepath +		sqrt(dis[nums[i]][nums[i+1]])
		}
	} while (next_permutation(nums.begin(), nums.end()));
	/*
	
	//B
	/*int n;
	string s;
	cin >> n;
	cin >> s;
	int i;
	if (n % 2 == 1) {
		cout << "No" << endl;
		return 0;
	}
	for (i = 0; i < n / 2; i++) {
		if (s[i] != s[i + (n / 2)]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;*/
}
long long int C(int n, int k) {
	//n kara k toridasu
	long long int i;
	long long int mod = 1000000007;
	long long int res = 1;
	if ((k == 0)||(k == n)) {
		return 1;
	}
	else {
		for (i = 0; i < k; i++) {
			res = (((res * (n - i)) % mod ) * modinv(i + 1, mod)) % mod;
		}
	}
	return res;
}
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
		while (n > 0) {
			if (n & 1) res = res * a % mod;
			a = a * a % mod;
			n >>= 1;
		}
	return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}