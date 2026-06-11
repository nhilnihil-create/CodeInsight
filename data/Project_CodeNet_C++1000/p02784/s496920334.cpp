#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	long long H, N, A;
	cin >> H >> N;
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> A;
		total += A;
	}
	if (H > total) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}