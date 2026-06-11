#include<iostream>
#include<vector>
using namespace std;

int main() {

	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	int s = 0;
	for (int i = 0; i < N; i++) s ^= a[i];
	for (int i = 0; i < N; i++) {
		int ans = a[i] ^ s;
		cout << ans << endl;
	}
	return 0;
}