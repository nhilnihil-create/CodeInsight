#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	double x;
	cin >> x;
	x = (x * x * x) / 27;
	printf("%.6f", x);
	return 0;
}
