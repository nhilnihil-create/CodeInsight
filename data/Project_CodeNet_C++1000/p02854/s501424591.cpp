#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) cin >> A[i];
	
	int i = 0, j = N - 1;
	int dif = 0;
	while (i <= j) {
		if (dif > 0) {
			dif -= A[j];
			j--;
		}
		else {
			dif += A[i];
			i++;
		}
	}
	cout << abs(dif) << endl;
}