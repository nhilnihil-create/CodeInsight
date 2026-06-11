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

	int ans;
	if (N % 2 == 1) ans = N / 2 + 1;
	else ans = N / 2;

	cout << ans << endl;

	return 0;
} 