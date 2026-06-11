#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
#include<iostream>
#include<iomanip>
using namespace std;

long long k, q;
long long d[5000];
long long n[5000];
long long x[5000];
long long m[5000];
long long sum;
long long sum_all;
long long diff;
int main() {
	cin >> k >> q;
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}

	for (int i = 0; i < q; i++) {
		cin >> n[i] >> x[i] >> m[i];
	}
	for (int i = 0; i < q; i++) {
		sum = (x[i] % m[i]);
		sum_all = 0;
		diff = 0;
		for (int j = 0; j < k; j++) {
			sum_all += d[j] % m[i];
			if (d[j] % m[i] == 0) {
				diff += 1;
			}
		}
		sum += sum_all * ((n[i] - 1) / k);
		diff = diff * ((n[i] - 1) / k);
		for (int j = 0; j < (n[i] - 1) % k; j++) {
			sum += d[j] % m[i];
			if (d[j] % m[i] == 0) {
				diff += 1;
			}
		}
//		cout << sum << " ";
//		if (sum < 0) { n[i] += 1; }
		cout << n[i] - 1 - sum / m[i] - diff << "\n";
	}
}