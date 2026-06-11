#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<int> B(N);
	B = A;
	sort(B.begin(), B.end(), greater<int>());
	int m1 = B[0], m2 = B[1];
	for (int i = 0; i < N; i++) {
		if (m1 == m2) cout << m1 << endl;
		else if (A[i] == m1) cout << m2 << endl;
		else cout << m1 << endl;
	}
	return 0;
}