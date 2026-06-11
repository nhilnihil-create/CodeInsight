#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	sort(S.begin(), S.end());
	vector<int> a(N, 0);
	int rec = 0;
	int Max = 0;
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == S[i + 1]) {
			rec++;
		}
		else {
			a[i] = rec;
			Max = max(Max, rec);
			rec = 0;
		}
	}
	if (rec > 0) {
		a[N - 1] = rec;
		Max = max(Max, rec);
	}
	for (int i = 0; i < N; i++) {
		if (a[i] == Max) {
			cout << S[i] << endl;
		}
	}
	return 0;
}