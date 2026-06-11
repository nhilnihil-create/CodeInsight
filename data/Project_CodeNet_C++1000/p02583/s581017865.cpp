#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <array>
using namespace std;


void comb(int *indices, int s, int rest, std::function<void(int*)> f) {
	if (rest == 0) {
		f(indices);
	}
	else {
		if (s < 0) return;
		comb(indices, s - 1, rest, f);
		indices[rest - 1] = s;
		comb(indices, s - 1, rest - 1, f);
	}
}
void comb_apply(int n, int s, function<void(int*)> f) {
	vector<int> idx(n);
	comb(idx.data(), s - 1, n, f);
}

int main() {
	int N;
	cin >> N;
	vector<int> L(N);
	set<array<int, 3>> matched;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> L[i];
	}
	int count = 0;
	comb_apply(3, L.size(), [&](int *indices) {
		int a = L[indices[0]];
		int b = L[indices[1]];
		int c = L[indices[2]];
		if ( a != b && a != c && c != b &&
			a + b > c && b + c > a && c + a > b) {
			++count;
		}	
	});
	cout << count << endl;
	return 0;
}