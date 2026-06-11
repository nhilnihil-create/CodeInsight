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
	vector<pair<int, int>> ans(N);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		ans[i] = make_pair(a, i + 1);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < N; i++) {
		cout << ans.at(i).second << " ";
	}
}
