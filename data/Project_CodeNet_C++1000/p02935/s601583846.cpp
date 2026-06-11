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
	int N; cin >> N;
	vector<float> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++) {
		v[i + 1] = (v[i] + v[i + 1]) / 2;
	}
	cout << v[N - 1] << endl;
}
