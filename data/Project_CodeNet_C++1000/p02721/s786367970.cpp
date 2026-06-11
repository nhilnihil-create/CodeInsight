#pragma GCC optimize("Ofast", "unroll-loops")

// #define TEST

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K, C;
	cin >> N >> K >> C;
	string S; cin >> S;
	vector<int> L(K);
	int ptr_L = 0, ptr_S = 0;
	while (ptr_L < K) {
		while (S[ptr_S] != 'o')
			++ptr_S;
		L[ptr_L++] = ptr_S;
		ptr_S += C + 1;
	}
#ifdef TEST
	for (auto i : L)
		cout << i << " ";
	cout << endl;
#endif
	vector<int> R(K);
	int ptr_R = K - 1;
	ptr_S = N - 1;
	while (ptr_R >= 0) {
		while (S[ptr_S] != 'o')
			--ptr_S;
		R[ptr_R--] = ptr_S;
		ptr_S -= C + 1;
	}
#ifdef TEST
	for (auto i : R)
		cout << i << " ";
	cout << endl;
#endif
	for (int i = 0; i < K; ++i)
		if (L[i] == R[i])
			cout << (L[i] + 1) << endl;
	return 0;
}