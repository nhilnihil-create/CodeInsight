#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n, k;
	cin >> n >> k;
	double P[n];
	rep(i, n) {
		cin >> P[i];
	}
	double E[n];
	double S[n+1];
	rep(i, n) {
		E[i] = (1 + P[i])/2;
		S[i+1] = S[i] + E[i];
	}

	double max_exp = 0;
	rep(i, n) {
		if (i+k > n) break;
		double exp;
		if (i==0) exp = S[i+k];
		else exp = S[i+k] - S[i];
		max_exp = max(exp, max_exp);
	}
	cout << fixed << setprecision(12);
	cout << max_exp << endl;
}