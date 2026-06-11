#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<pair<int, int>, int> Map;
int N, X[59], Y[59], maxn;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			Map[make_pair(X[j] - X[i], Y[j] - Y[i])]++; maxn = max(maxn, Map[make_pair(X[j] - X[i], Y[j] - Y[i])]);
			Map[make_pair(X[i] - X[j], Y[i] - Y[j])]++; maxn = max(maxn, Map[make_pair(X[i] - X[j], Y[i] - Y[j])]);
		}
	}
	cout << N - maxn << endl;
	return 0;
}