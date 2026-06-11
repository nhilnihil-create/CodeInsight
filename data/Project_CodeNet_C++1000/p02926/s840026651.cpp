#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
 
struct st {
	double x, y;
} a[105];
int n;
double x, y, ans;
 
bool cmp(st p, st q) {
	return atan2(p.y, p.x) < atan2(q.y, q.x);
}
 
int main() {
	int i, j, c;
	cin >> n;
	for(i=0; i<n; i++) cin >> a[i].x >> a[i].y;
	sort(a, a+n, cmp);
	for(i=0; i<n; i++) {
		x=0.0, y=0.0;
		for(j=i, c=0; c<n; j++, c++) {
			x += a[j%n].x;
			y += a[j%n].y;
			ans = max(ans, sqrt(x*x + y*y));
		}
	}
	printf("%.15f", ans);
	return 0;
}