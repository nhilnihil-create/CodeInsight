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
#define coutfix(i) cout << fixed << setprecision(i)		//coutの浮動小数出力の桁数設定
using namespace std;

int main()
{
	int64 tmp;
	multiset<int64> memo;
	for(int64 ii = 0;ii < 3;ii++)
	{
		cin >> tmp;
		memo.insert(tmp);
	}
	auto ite = memo.begin();
	tmp = *ite;
	ite++;
	tmp += *ite;
	cout << tmp << endl;
	return 0;
}