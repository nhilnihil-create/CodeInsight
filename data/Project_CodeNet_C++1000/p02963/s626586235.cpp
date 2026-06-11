#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main(){
	long long s;
	cin >> s;
	long long m = 1000000000;
	long long c;
	long long d = (s + m - 1) / m;
	if ((s + m - 1) / m != s / m) {
		c = m - s % m;
	}
	else {
		c = 0;
	}
	cout << "0 0 1000000000 1 " << c << " " << d << endl;
	return 0;
}