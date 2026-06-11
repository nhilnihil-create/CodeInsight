#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
int main() {
	double m, a=0, n, sum=0;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vector<double>s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < n; i++) {
			sum += s[i];
		}
		m = sum / n;
		for (int i = 0; i < n; i++) {
			a += pow(s[i] - m, 2);
		}
		a = a / n;
		a = pow(a, 0.5);
		printf("%.10lf\n",a);
		a = 0;
		m = 0;
		sum = 0;
	}
}