#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	int N, d;
	cin >> N;
	int total = 0;
	vector<int> happy(N);
	for (int i = 0; i < N; i++) {
		cin >> d;
		happy.at(i) = d;
	}
	for (int j = 0; j < N - 1; j++) {
		for (int k = 1 + j; k < N; k++) {
			total += happy.at(j) * happy.at(k);
		}
	}
	cout << total << endl;
}