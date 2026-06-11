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
	int N;
	cin >> N;
	vector<int> An(N, 0);
	bool judge = true;
	rep(i, N) {
		cin >> An[i];
		if (An[i] % 2 == 0) {
			if (An[i] % 3 != 0 && An[i] % 5 != 0) {
				judge = false;
			}
		}
	}

	if (judge) {
		cout << "APPROVED" << endl;
	}
	else {
		cout << "DENIED" << endl;
	}

	return 0;
} 