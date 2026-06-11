#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

pair<double, double> a[9];
int perm[9];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		perm[i] = i;
		cin >> a[i].first >> a[i].second;
	}
	double tot = 0;
	do {
		double cur = 0;
		for(int i = 2; i <= n; ++i)
			cur += sqrt(abs(a[perm[i]].first - a[perm[i - 1]].first) * abs(a[perm[i]].first - a[perm[i - 1]].first) +
						abs(a[perm[i]].second - a[perm[i - 1]].second) * abs(a[perm[i]].second - a[perm[i - 1]].second));
		tot += cur;
	} while(next_permutation(perm + 1, perm + n + 1));
	int fact = 1;
	for(int i = 1; i <= n; ++i)
		fact *= i;
	cout << fixed << setprecision(7) << tot / fact;
}
