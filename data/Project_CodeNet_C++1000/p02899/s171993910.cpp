#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;
long long INF = 1LL << 60;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), order(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		order[A[i] - 1] = i + 1;
	}
	for (int i = 0; i < N; i++) cout << order[i] << " ";
	return 0;
}