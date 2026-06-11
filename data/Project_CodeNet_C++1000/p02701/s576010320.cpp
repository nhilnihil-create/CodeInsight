#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	map<string, bool> M;
	int kind = 0;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		if (M[S[i]]) continue;
		else {
			M[S[i]] = true;
			kind++;
		}
	}
	cout << kind << endl;
	return 0;
}