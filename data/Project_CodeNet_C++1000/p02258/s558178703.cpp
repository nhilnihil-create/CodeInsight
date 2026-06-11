#include <stdio.h>
//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int main(int **argc) {

	int n;
	cin >> n;

	int mn = INT_MAX;
	int mx = -1;
	int diffMax = INT_MIN;
	for (int i = 0;i<n;i++) {
		int tmp;
		cin >> tmp;
		diffMax = max(tmp - mn, diffMax);
		mn = min(mn, tmp);
	}

	cout << diffMax << endl;
	return 0;
}