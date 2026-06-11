#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long s, xx1, yy1, xx2, yy2, xx3, yy3;
	cin >> s;
	xx1 = 0; yy1 = 0;
	xx2 = 1000000000; yy2 = 1;
	if (s % 1000000000 == 0) {
		yy3 = s / 1000000000;
		xx3 = 0;
	}
	else {
		yy3 = s / 1000000000 + 1;
		xx3 = yy3 * 1000000000 - s;
	}

	cout << xx1 << " " << yy1 << " " << xx2 << " " << yy2 << " " << xx3 << " " << yy3 << "\n";

	return 0;
}
