#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define rep(i,a,n) for(int (i)=a;(i)<(int)(n);(i)++)
#define rrep(i,a,n) for(int (i)=(n)-1;(i)>=a;(i)--)
#define all(x) (x).begin(),(x).end()

typedef long long ll;

int main() {
	double r;
	cin >> r;

	double ans1, ans2;

	ans1 = M_PI * r * r;
	ans2 = M_PI * 2 * r;

	printf("%.6f %.6f\n", ans1, ans2);
}