#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100100;

int k;
char s[N];

int main() {

	scanf("%s %d", s, &k);

	int n = strlen(s);
	long long res = 0;

	vector <int> c;

	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && s[i] == s[j]) {
			j++;
		}
		c.push_back(j - i);
		i = j;
	}

	if (k == 1 || s[0] != s[n - 1]) {
		for (int i = 0; i < c.size(); i++) {
			res += 1LL * k * (c[i] / 2);
		}
	} else if (c.size() == 1) {
		res += (1LL * k * n) / 2;
	} else {
		for (int i = 0; i < c.size(); i++) {
			res += c[i] / 2;
		}
		for (int i = 1; i + 1 < c.size(); i++) {
			res += 1LL * (k - 1) * (c[i] / 2);
		}
		res += 1LL * (k - 1) * ((c[0] + c[c.size() - 1]) / 2);
	}

	printf("%lld\n", res);

	return 0;

}