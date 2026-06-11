#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	int N, K, p;
	cin >> N >> K;
	int total;
	total = 0;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> p;
		vec.at(i) = p;
	}
	sort(vec.begin(), vec.end());
	for (int j = 0; j < K; j++) {
		total += vec.at(j);
	}
	cout << total << endl;
}