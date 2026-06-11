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

ll box(double a)
{
	ll b = a;
	return b;
}

int main() {
	ll n, k, r, s, p;
	cin >> n >> k >> r >> s >> p;
	string t;
	cin >> t;
	ll counta = 0;
	ll countb = 0;
	ll countc = 0;
	vl kiroku(n);
	for (int i = 0; i < n; i++) {
		if (i < k) { //検証必要あり
			if (t[i] == 'r') {
				kiroku[i] = 1;
			}
			if (t[i] == 's') {
				kiroku[i] = 2;
			}
			if (t[i] == 'p') {
				kiroku[i] = 3;
			}
		}
		else {
			if (t[i] != t[i - k]) {
				if (t[i] == 'r') {
					kiroku[i] = 1;
				}
				if (t[i] == 's') {
					kiroku[i] = 2;
				}
				if (t[i] == 'p') {
					kiroku[i] = 3;
				}
			}
			else {
				if (t[i] == 'r') {
					if (kiroku[i - k] == 1) {
						kiroku[i] = 4;
					}
					else {
						kiroku[i] = 1;
					}
				}
				if (t[i] == 's') {
					if (kiroku[i - k] == 2) {
						kiroku[i] = 4;
					}
					else {
						kiroku[i] = 2;
					}
				}
				if (t[i] == 'p') {
					if (kiroku[i - k] == 3) {
						kiroku[i] = 4;
					}
					else {
						kiroku[i] = 3;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (kiroku[i] == 1) {
			counta++;
		}
		if (kiroku[i] == 2) {
			countb++;
		}
		if (kiroku[i] == 3) {
			countc++;
		}
	}
	cout << counta * p + countb * r + countc * s << endl;
	return 0;
}