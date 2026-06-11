#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	for(int A = 1; A < 10; A++) {
		if(N % A == 0) {
			int B = N / A;
			if(1 <= B && B <= 9) {
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";
	return 0;
}