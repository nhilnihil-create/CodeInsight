#include <iostream>
#include <string>
#include <stddef.h>
#include <stack>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#define ll long long;

using namespace std;

int n;
double ss;
int s[1000];
double m;
double a;

double mean(int s[]) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i];
	}
	return (double)sum / n;
}

int main() {
	

	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		m = mean(s);
		ss = 0;
		for (int i = 0; i < n; i++) {
			ss += (s[i] - m)*(s[i] - m);
		}
		a = sqrt(ss / n);
		printf("%.8f\n", a);
	}
}