#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, X, T;
	cin >> N >> X >> T;
	int a = N / X;
	if (N % X) cout << (a + 1) * T << endl;
	else cout << a * T << endl;
}