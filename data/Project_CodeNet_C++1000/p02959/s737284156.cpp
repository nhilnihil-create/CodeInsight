#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> A(n + 1);
	vector<long long> B(n);
	for (int i = 0; i < n + 1; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (B[i] >= A[i]) {
			ans += A[i];
			B[i] -= A[i];

			if (B[i] >= A[i + 1]) {
				ans += A[i + 1];
				A[i + 1] = 0;
			}
			else {
				ans += B[i];
				A[i + 1] -= B[i];
			}
		}
		else ans += B[i];
	}
	cout << ans << endl;
}