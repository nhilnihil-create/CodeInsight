#include <bits/stdc++.h>
using namespace std;

int main() {
	int N ,X, L;
	cin >> N >> X;
	int total = 0;
	int count = 0;
	for (int i = 0; i < N + 1; i++) {
		cin >> L;
		total += L;
		count += 1;
		if (total <= X) {
			continue;
		}
		else {
			break;
		}
	}
	cout << count << endl;
}