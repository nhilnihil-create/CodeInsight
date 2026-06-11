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
	string S, T;
	cin >> N;
	cin >> S >> T;

	string ret;

	for (int i = 0; i < N; ++i) {
		ret.push_back(S[i]);
		ret.push_back(T[i]);
	}

	cout << ret << endl;
	return 0;
}
