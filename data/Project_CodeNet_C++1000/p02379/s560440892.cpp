// class point	の練習（クラスの高度な実装）
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long llong;
using namespace std;

int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout <<fixed<<setprecision(10)<< sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return 0;
}

