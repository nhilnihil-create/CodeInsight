#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	map<int, int> M;
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		M[A[i]]++;
	}
	string ans = "YES";
	for (auto num : M) {
		if (num.second >= 2) ans = "NO";
	}
	cout << ans << endl;
	return 0;
}