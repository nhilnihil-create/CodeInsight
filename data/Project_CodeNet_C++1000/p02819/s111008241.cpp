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
	int X;
	cin >> X;
	ll tg = sqrt(X);

	while (true) {
		bool find = true;
		for (ll i = 2; i <= tg; ++i) {
			if (X % i == 0) {
				find = false;
				break;
			}
		}

		if (find) {
			cout << X << endl;
			return 0;
		}
		X += 1;
	}

	return 0;
} 
