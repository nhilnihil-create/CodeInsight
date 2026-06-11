#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B.begin(), B.end());
	int Max = B[N - 1];
	int Mid = B[N - 2];
	for (int i = 0; i < N; i++) {
		if (Mid == Max) {
			cout << Max << endl;
		}
		else {
			if (A[i] == Max) {
				cout << Mid << endl;
			}
			else {
				cout << Max << endl;
			}
		}
	}
	return 0;
}