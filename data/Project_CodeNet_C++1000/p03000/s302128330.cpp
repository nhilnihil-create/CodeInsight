#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	vector<int> L(N);
	for (int i = 0; i < N; i++) cin >> L[i];
	int D = 0, count = 1;
	for (int i = 0; i < N; i++) {
		D += L[i];
		if (D <= X) count++;
	}
	cout << count << endl;
	return 0;
}