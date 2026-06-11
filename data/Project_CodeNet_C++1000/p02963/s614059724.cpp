#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; ++i)

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	LLONG S; cin >> S;
	const int nine = 1000000000;
	int x2 = nine;
	int y2 = 1;
	int x3 = S % nine == 0 ? 0 : nine - S % nine;
	int y3 = (S + x3) / nine;
	cout << "0 0 " << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
}