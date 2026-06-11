#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <list>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <iomanip>
#define INF 2147483647

using namespace std;



int main()
{
	double s[1005], ave, a;
	int n;

	while (1) {
		cin >> n;
		if (n == 0) break;
		ave = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			ave += s[i];
		}
		ave /= n;
		a = 0;
		for (int i = 0; i < n; i++) {
			a += pow((s[i] - ave), 2);
		}
		a /= n;
		cout << fixed << setprecision(8) << sqrt(a) << endl;
	}

	return (0);
}