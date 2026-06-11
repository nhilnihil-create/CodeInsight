#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

long long N, c1, c2, c3, cnt;
string S;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') c1++;
		if (S[i] == 'G') c2++;
		if (S[i] == 'B') c3++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int k = j + (j - i); if (k >= N) continue;
			if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) cnt--;
		}
	}
	cnt += c1 * c2 * c3;
	cout << cnt << endl;
	return 0;
}