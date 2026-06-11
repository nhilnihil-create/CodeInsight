#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;

void swap(pair<int, int>& a, pair<int, int>& b) {
	auto tmp = a;
	a = b;
	b = tmp;
}

void sort(vector<pair<int, int>>& arr, int l, int r) {
	if (r - l <= 1) return;

	int pivotIndex = r - 1;
	auto pivot = arr[pivotIndex];

	int i = l;
	for (int j = l; j < r - 1; ++j) {
		if (arr[j].second < pivot.second) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r - 1]);

	sort(arr, l, i);
	sort(arr, i + 1, r);
}


int main() {
	double N;
	cin >> N;

	vector<pair<int, int>> A(N);

	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		A[i] = make_pair(i + 1, a);
	}
	
	sort(A, 0, A.size());

	string ans = "";
	for (int i = 0; i < A.size(); ++i) {
		ans  += to_string(A[i].first);
		if (i != A.size() - 1) {
			ans += " ";
		}
	}
	cout << ans << endl;
	return 0;
}
