#include <iostream>
using namespace std;
int main() {
	int N, X;
	cin >> N >> X;
	int sum = 0, ans = 1;
	for (int i = 0; i < N; ++i) {
		int L;
		cin >> L;
		sum += L;
		if (sum <= X) ++ans;
	}
	cout << ans << endl;
	return 0;
}