#include <iostream>
using namespace std;

int a[200005];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N; cin >> N;

	int all = 0;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		all ^= a[i];
	}

	for (int i = 1; i <= N; i++) {
		int ans = 0;
		for (int l = 0; (1 << l) <= a[i] || (1 << l) <= all; l++) {
			if (((1 << l) & a[i]) ^ ((1 << l) & all)) ans += (1 << l);
		}
		cout << ans << ' ';
	}

	return 0;
}