#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	vector<string> T;
	map<string, int> M;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		M[S[i]]++;
		count = max(count, M[S[i]]);
	}
	for (auto temp : M) {
		if (temp.second == count) T.push_back(temp.first);
	}
	sort(T.begin(), T.end());
	for (string t : T) cout << t << endl;
	return 0;
}