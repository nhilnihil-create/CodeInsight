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
	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i <= (N-3); ++i) {
		string t = s.substr(i, 3);
		if (t == "ABC") cnt += 1;
	}

	cout << cnt << endl;
	return 0;
} 