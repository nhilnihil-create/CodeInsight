#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)

int main() {
	string S;
	string T="abc";
	cin >> S;
	int i;
	rep(i, 3) {
		T[i] = S[i];
	}
	cout << T;
	return 0;
}