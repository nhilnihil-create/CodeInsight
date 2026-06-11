#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
#include <set>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };
const double PI = 3.14159265358979323846;


int main() {

	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a.at(i);
	}
	int max_dist = abs(k - a.at(n - 1)) + abs(0 - a.at(0));

	rep(i, n - 1) {
		int num = 0;
		num = abs(a.at(i) - a.at(i + 1));
		max_dist = max(max_dist, num);
	}

	cout << k - max_dist << endl;


	return 0;

}

