#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 2e5 + 5;
int a[N], b[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < min(k, 60); i++) {
		for (int j = 0; j < n; j++)
			b[j] = 0;

		for (int j = 0; j < n; j++) {
			b[max(0, j - a[j])]++;
			b[min(n, j + a[j] + 1)]--;
		}

		for (int j = 0; j < n; j++) {
			b[j + 1] += b[j];
			a[j] = b[j];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}