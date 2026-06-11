#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<int> correct(N, 0);
	for (int i = 0; i < Q; i++) {
		int A;
		cin >> A;
		A--;
		correct[A]++;
	}
	for (int i = 0; i < N; i++) {
		if (correct[i] > (Q - K)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}