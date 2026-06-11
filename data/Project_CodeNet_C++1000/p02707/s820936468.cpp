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
#include<functional>

using namespace std;
typedef long long ll;



int main() {
	int N; cin >> N;
	vector<int> S(N, 0);
	vector<int> A(N - 1);
	for (int i = 0; i < N - 1; i++) {
		cin >> A[i];
		S[A[i] - 1]++;
	}
	for (int i = 0; i < N; i++) cout << S[i] << endl;
}
