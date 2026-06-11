#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;

int main()
{
	int A, B;
	cin >> A >> B;
	vector<int> mp(3, 1);
	mp[A - 1]--;
	mp[B - 1]--;

	for (int i = 0; i < 3; ++i) {
		if (mp[i] == 1) {
			cout << i + 1 << endl;
		}
	}
	return 0;
}
