#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100
const double PI = acos(0) * 2;
int x[N], y[N];

pair<double, int> in[N];
int main(void) {
	//solve 
	
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &x[i], &y[i]);
			in[i] = make_pair(atan2(x[i], y[i]), i);
		}
		sort(in, in + n);
		long long ret = 0;
		for (int i = 0; i < n; ++i) {
			long long X = 0, Y = 0;
			for (int j = i; j < i + n; ++j) {
				int ind = j % n, id = in[ind].second;
				X += x[id], Y += y[id];
				ret = max(ret, X*X + Y * Y);
			}
		}
		printf("%0.10lf\n", sqrt(ret));
	
	return 0;
}