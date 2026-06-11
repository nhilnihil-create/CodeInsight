#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll countn = 0;
	ll countm = 0;
	ll memoa = 0;
	ll memob = 0;
	ll countx = 0;
	ll county = 0;
	countn = b - b / c;
	countm = b - b / d;
	memoa = b - b / lcm(c, d);
	countx = (a-1) - (a-1) / c;
	county = (a-1) - (a-1) / d;
	memob = (a-1) - (a-1) / lcm(c, d);
	cout << (countn + countm - memoa) - (countx + county - memob) << endl;
}