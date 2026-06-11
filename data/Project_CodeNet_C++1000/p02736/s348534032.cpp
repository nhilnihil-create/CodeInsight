#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int) 2e6;

int n;
char s[N];
vector <int> a;

bool check(int n, int k) {
	return ((n - k) & k) == 0;
}

int main() {

	scanf("%d %s", &n, s);

	for (int i = 0; i < n - 1; i++) {
		a.push_back((int) abs(s[i] - s[i + 1]));
	}

	n--;

	vector <int> cnt(3, 0);

	for (int x : a) {
		cnt[x]++;
	}

	int coeff = 1;

	if (cnt[1] == 0) {
		coeff *= 2;
		for (int i = 0; i < a.size(); i++) {
			a[i] >>= 1;
		}
	}

	int res = 0;

	for (int i = 0; i < n; i++) {
		if (check(n - 1, i)) {
			res ^= a[i];
		}
	}

	printf("%d\n", (res & 1) * coeff);

	return 0;

}