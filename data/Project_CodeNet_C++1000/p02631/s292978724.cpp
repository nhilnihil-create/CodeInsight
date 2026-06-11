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
		cout << (a[i] ^ all) << ' ';
	}

	return 0;
}