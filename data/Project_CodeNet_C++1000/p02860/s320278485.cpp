#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	string S;
	cin >> N >> S;

	if(N % 2) {
		cout << "No";
		return 0;
	}

	for(int i = 0; i < N / 2; i++) {
		if(S[i] != S[i + N / 2]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}