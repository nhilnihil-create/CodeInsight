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
using namespace std;
typedef long long ll;

int main() {
	int N; cin >> N;
	bool judge = false;
	for (int i = N; i < 1e9; i++) {
		int cnt = 0;
		for (int j = 2; j*j <= N; j++) {
			if (i % j == 0) cnt++;
		}
		if (cnt == 0) {
			cout << i << endl;
			return 0;
		}
	}
}