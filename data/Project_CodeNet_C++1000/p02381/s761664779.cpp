#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int main() {
	int n;
	while(scanf("%d", &n), n) {
		double s[1010], sum = 0.0;
		rep(i,n) {
			cin >> s[i];
			sum += s[i];
		}
		sum = sum / n;
		double ret = 0;
		rep(i,n) {
			ret += pow((sum - s[i]), 2.0);
		}
		printf("%.10lf\n", sqrt(ret / n));
	}
	return 0;
}