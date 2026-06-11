#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, S = 1, cnt;

int main() {
	cin >> N;
	for (long long i = 2; i * i <= N; i++) {
		long long cx = N;
		while (cx >= i) {
			if (cx % i == 0) cx /= i;
			else cx %= i;
		}
		if (cx == 1) cnt++;
		S = i;
	}

	vector<long long> V;
	for (long long i = 1; i * i <= N - 1; i++) {
		if ((N - 1) % i != 0) continue;
		V.push_back(i);
		V.push_back((N - 1) / i);
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	for (int i = 0; i < V.size(); i++) {
		if (V[i] > S) cnt++;
	}
	cnt++;

	cout << cnt << endl;
	return 0;
}