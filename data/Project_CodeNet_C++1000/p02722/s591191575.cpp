#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	long long int n;
	cin >> n;
	long long int res = 1;
	for (long long int i = 1; i * i <= n - 1; i++) {
		if ((n - 1) % i == 0) {
			long long int a = i, b = (n - 1) / i;
			if (a == b) {
				if (n % a != 0) res++;
			} else {
				if (n % a != 0) res++;
				if (n % b != 0) res++;
			}
		}
	}
	long long int nn = n;
	for (long long int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			nn = n;
			while (nn % i == 0) nn /= i;
			if ((nn - 1) % i == 0) res++;
		}
	}
	cout << res << endl;
}
