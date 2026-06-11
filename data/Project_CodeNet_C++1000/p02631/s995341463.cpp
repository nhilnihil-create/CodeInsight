#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

int main() {
	int N, L = 0;
	cin >> N;
	vector<int> A(N);
	for (int i = 0;i < N;i++) {
		cin >> A[i];
		L ^= A[i];
	}
	for (int i = 0;i < N;i++) {
		cout << (A[i] ^ L);
		if (i == N - 1)cout << endl;
		else cout << " ";
	}
}
