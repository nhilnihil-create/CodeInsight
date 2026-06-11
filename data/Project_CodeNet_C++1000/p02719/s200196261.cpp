#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	ll N, K;
	cin >> N >> K;
	N %= K;
	cout << min(N, K - N) << endl;
}