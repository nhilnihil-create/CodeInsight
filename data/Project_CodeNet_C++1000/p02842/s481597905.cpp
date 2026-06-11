#include <iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	double a = 1.08;
	for (int i = 0; i <= N; i++) {
		if (floor((double)(i * a)) == N) {
			cout << i << endl;
	        return 0;
		}
	}
	cout << ":(" << endl;
	}