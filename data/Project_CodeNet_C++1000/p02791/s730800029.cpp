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
#include <map>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int N;
	cin >> N;
	int A;
	int ans = 0;
	int maxa = 2147483647;
	rep(i, N) {
		cin >> A;
		maxa = min(maxa, A);
		if (A <= maxa) { ans++; }
	}
	cout << ans;
}