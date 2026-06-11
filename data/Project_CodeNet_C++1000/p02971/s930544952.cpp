#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<int> B(N);
	for (int i = 0; i < N; i++) B[i] = A[i];
	sort(B.begin(), B.end());
	for (int i = 0; i < N; i++) {
		if (A[i] == B[N - 1]) cout << B[N - 2] << endl;
		else cout << B[N - 1] << endl;
	}
}
