#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int diff = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x != i + 1) ++diff;
	}
	cout << (diff <= 2 ? "YES" : "NO") << endl;
	return 0;
}