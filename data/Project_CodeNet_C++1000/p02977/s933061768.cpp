#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int b = 1;
	while (b * 2 <= N) b *= 2;
	if (b == N) {
		cout << "No" << endl;
	}
	else if (N == 3) {
		cout << "Yes" << endl;
		cout << 1 << ' ' << 2 << endl;
		cout << 2 << ' ' << 3 << endl;
		cout << 3 << ' ' << 4 << endl;
		cout << 4 << ' ' << 5 << endl;
		cout << 5 << ' ' << 6 << endl;
	}
	else {
		cout << "Yes" << endl;
		cout << b << ' ' << 1 << endl;
		cout << 1 << ' ' << b + 1 << endl;
		cout << b + 1 << ' ' << b + N << endl;
		cout << b + N << ' ' << 1 + N << endl;
		cout << 1 + N << ' ' << b + 1 + N << endl;
		for (int i = 2; i < b - 1; ++i) {
			cout << i << ' ' << i + 1 << endl;
		}
		cout << b - 1 << ' ' << 1 + N << endl;
		for (int i = 1; i < b - 1; ++i) {
			cout << i + N << ' ' << i + 1 + N << endl;
		}
		vector<int> seq;
		for (int i = 2; i < b; ++i) {
			seq.push_back(i);
		}
		for (int i = 1; i < b; ++i) {
			seq.push_back(i);
		}
		vector<int> rui(seq.size());
		int d = seq.size() / 2;
		rui[d] = seq[d];
		for (int i = d - 1; i >= 0; --i) {
			rui[i] = rui[i + 1] ^ seq[i];
		}
		for (int i = d + 1; i < seq.size(); ++i) {
			rui[i] = rui[i - 1] ^ seq[i];
		}
		vector<int> pos(b * 2, -1);
		for (int i = 0; i < seq.size(); ++i) {
			pos[rui[i] ^ b] = i;
		}
		for (int i = 0; i <= N; ++i) {
			if (pos[i] != -1) {
				if (pos[i] < d) pos[i] += 2;
				else pos[i] -= d, pos[i] += 1, pos[i] += N;
			}
		}
		for (int i = b + 2; i <= N; ++i) {
			cout << i << ' ' << b + N << endl;
			cout << i + N << ' ' << pos[i] << endl;
		}
	}
	return 0;
}