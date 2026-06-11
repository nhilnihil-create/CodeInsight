#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
	int N; cin >> N;
	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		int a; cin >> a; a--;
		A[a]++;
	}
	sort(A.begin(), A.end(), greater<int>());

	vector<int> B(N, 0);
	int c = 0;
	if (A[N - 1] == 1) { B[c] = N; c++; }
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] != A[i + 1]) {
			while (c < A[i]) {
				B[c] = i + 1;
				c++;
			}
		}
	}
	vector<int> v(N, 0);
	int s = 0;
	for (int i = 0; i < N; i++) {
		s += B[i];
		v[i] = s / (i + 1);
	}

	c = N - 1;
	for (int i = 0; i < N; i++) {
		while (c >= 0 && v[c] < (i + 1)) { c--; }
		cout << c + 1 << endl;
	}

	return 0;
}