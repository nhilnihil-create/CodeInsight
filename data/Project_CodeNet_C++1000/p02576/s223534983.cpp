#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, X, Y;
	cin >> N >> X >> Y;
	int count = 0;

	while (N > 0) {
		count++;
		N -= X;
	}cout << count * Y;
}