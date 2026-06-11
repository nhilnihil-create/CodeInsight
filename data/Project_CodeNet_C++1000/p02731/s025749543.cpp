#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <cassert>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	double N;
	cin >> N;
	N /= 3.0;
	N = pow(N, 3.0);
	cout << fixed << setprecision(8) << N;
}