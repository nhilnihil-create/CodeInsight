// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000;

int pp[N], qq[N];

int main() {
	int n, k, c; cin >> n >> k >> c;
	string s; cin >> s;
	for (int h = 0, i = 0, o = i - c - 1; i < n; i++)
		if (s[i] == 'o' && i - o > c) {
			pp[h] = o = i;
			if (++h == k)
				break;
		}
	for (int h = 0, i = n - 1, o = i + c + 1; i >= 0; i--)
		if (s[i] == 'o' && o - i > c) {
			qq[k - 1 - h] = o = i;
			if (++h == k)
				break;
		}
	for (int h = 0; h < k; h++)
		if (pp[h] == qq[h])
			cout << pp[h] + 1 << '\n';
	return 0;
}
