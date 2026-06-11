#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, tmp;
	cin >> nn;
	vector<pair<int64, int64>> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> tmp;
		aa[ii] = make_pair(tmp, ii + 1);
	}
	sort(aa.begin(), aa.end());
	for(int64 ii = 0;ii < nn;ii++)
	{
		cout << aa[ii].second;
		if(ii != nn  - 1)
		{
			cout << ' ';
		}
	}
	cout << endl;
	return 0;
}
