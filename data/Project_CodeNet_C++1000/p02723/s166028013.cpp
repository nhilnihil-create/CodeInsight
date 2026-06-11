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

	string s;
	cin >> s;
	int cnt = 0;

	if (s.at(2) == s.at(3)) cnt++;
	if (s.at(4) == s.at(5)) cnt++;

	if (cnt == 2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


	return 0;

}

