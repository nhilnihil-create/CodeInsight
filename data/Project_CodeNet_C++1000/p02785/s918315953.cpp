#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <map>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	if (K >= N) {
		cout << "0";
		return 0;
	}
	vector<int> A(N);
	rep(i, N) {
		cin >> A[i];
	}
	long long ans = 0;
	sort(A.begin(), A.end(), greater<int>());
	for (auto itr = A.begin()+K; itr != A.end(); itr++) {
		ans += *itr;
	}
	cout << ans;
}