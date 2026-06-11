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
	int N;
	string S;
	cin >> N >> S;
	int ans = 0;
	for (int i = 0; i <= N - 3; i++) {
		string t = S.substr(i, 3);
		if (t == "ABC") ans++;
	}
	cout << ans << endl;
}
