// Problem Code: abc177_e

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string coprime(int N, vector<int>& A) {
	int g = A[0], mx = *max_element(A.begin(), A.end());
	vector<bool> is_factor(mx);
	
	// gcd of all the elements
	for (int& x: A)
		g = __gcd(x, g);
	if (g > 1)
		return "not coprime";
	
	// check for pairwise coprime
	for (int x: A) {
		for (int y = 2; y * y <= x; y++)
			if (x % y == 0) {
				if (is_factor[y])
					return "setwise coprime";
				while (x % y == 0)
					x /= y;
				is_factor[y] = true;
			}
		if (x > 1) {
			if (is_factor[x])
				return "setwise coprime";
			is_factor[x] = true;
		}
	}
	
	return "pairwise coprime";
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << coprime(N, A);
	return 0;
}