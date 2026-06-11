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
	vector<string> s(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
	}
	long long count = 0;
	unordered_map<string, int> M;
	for (int i = 0; i < N; i++) {
		if (M[s[i]] != 0) count += M[s[i]];
		M[s[i]]++;
	}
	cout << count << endl;
	return 0;
}