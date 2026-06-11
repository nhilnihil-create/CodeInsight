#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> P;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		P.push_back(p);
	}

	int count = 0;
	for (int i = 1; i < N-1; i++) {
		if (P[i - 1] < P[i] && P[i] < P[i + 1]) {
			count++;
		}
		else if (P[i - 1] > P[i] && P[i] > P[i + 1]) {
			count++;
		}
	}
	cout << count << endl;
}
