#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
string S;
vector<int> path;

bool rec(int p) {
	if (p <= M) {
		path.push_back(p);
		return true;
	}
	for (int i = M; i >= 1; --i) {
		if (S[p - i] == '0') {
			path.push_back(i);
			return rec(p - i);
		}
	}
	return false;
}

int main(void) {
	cin >> N >> M;
	cin >> S;

	bool ans = rec(N);

	if (ans) {
		for (int i = (int)path.size() - 1; i >= 0; --i) {
			cout << path[i];
			if (i != 0)	cout << ' ';
			else		cout << '\n';
		}
	}
	else
		cout << "-1\n";
	return 0;
}
