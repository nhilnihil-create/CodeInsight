#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int K, N;
	cin >> N >> K;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	sort(H.begin(), H.end(), greater<int>());
	long long sum = 0;
	for (int i = K; i < N; i++) sum += H[i];
	cout << sum << endl;
	return 0;
}