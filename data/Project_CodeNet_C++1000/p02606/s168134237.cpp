
#include "math.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <numeric>
#include <cmath>
using namespace std;

int t;

int main()
{
	int l, r, d;
	cin >> l >> r >> d;
	int ans = floor(r*1.0 / d) - floor(l*1.0/d);
	if (l%d == 0 && r % d == 0) ans++;
	cout << ans;
	return 0;
}
