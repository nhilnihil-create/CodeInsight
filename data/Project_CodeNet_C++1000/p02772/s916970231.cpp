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

void cheak(vector<int> a);

int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a.at(i);
	}

	cheak(a);


	return 0;

}

void cheak(vector<int> a) {

	rep(i, size(a)) {

		if (a.at(i) % 2 == 0) {
			if (a.at(i) % 3 != 0 && a.at(i) % 5 != 0) {
				cout << "DENIED" << endl;
				break;
			}
		}
		if (i == (size(a) - 1)) cout << "APPROVED" << endl;
	}

}

