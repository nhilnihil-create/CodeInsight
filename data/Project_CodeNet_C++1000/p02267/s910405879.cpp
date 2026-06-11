#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int d;
	vector<int> S;
	for (int i = 0; i < n; ++i) {
		cin >> d;
		S.push_back(d);
	}
	int q;
	cin >> q;
	vector<int> T;
	for (int i = 0; i < q; ++i) {
		cin >> d;
		T.push_back(d);
	}

	int count = 0;
	for (int j = 0; j < q; ++j) {
		for (int i = 0; i < n; ++i) {
			if (T[j] == S[i]) {
				++count;
				break;
			}
		}
	}
	cout << count << endl;
}