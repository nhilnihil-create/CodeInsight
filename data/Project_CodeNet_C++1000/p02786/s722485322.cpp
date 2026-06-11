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
	long long H;
	cin >> H;
	ll score = 0;
	ll split = 1;
	while (H != 1) {
		score += split;
		H = H / 2;
		split *= 2;
	}
	score += split;

	cout << score << endl;
	return 0;
} 