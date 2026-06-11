#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M; string S;
	cin >> N >> M >> S;
	vector<int> safe;
	for (int i = 0; i <= N; ++i) {
		if (S[i] == '0') {
			safe.push_back(i);
		}
	}
	bool ok = true;
	for (int i = 1; i < safe.size(); ++i) {
		if (safe[i] - safe[i - 1] > M) {
			ok = false;
			break;
		}
	}
	if (!ok) {
		cout << -1 << endl;
	}
	else {
		int ptr = int(safe.size()) - 1;
		vector<int> seq;
		while (ptr > 0) {
			int cur = ptr;
			while (ptr > 0 && safe[cur] - safe[ptr - 1] <= M) --ptr;
			seq.push_back(safe[cur] - safe[ptr]);
		}
		for (int i = int(seq.size()) - 1; i >= 0; --i) {
			cout << seq[i];
			if (i > 0) cout << ' ';
		}
		cout << endl;
	}
}