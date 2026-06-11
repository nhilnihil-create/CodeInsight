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
	int N, K, S;
	cin >> N >> K >> S;
	vector<int> A(N, 1e9);
	for (int i = 0; i < K; i++) A[i] = S;
	if (S == 1e9) {
		for (int i = K; i < N; i++) A[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
}
