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
	double x1, x2, y1, y2, D;
	cin >> x1 >> y1 >> x2 >> y2;
	D = pow(x1 - x2, 2) + pow(y1 - y2, 2);
	D = pow(D, 0.5);
	printf("%.6lf\n", D);
}