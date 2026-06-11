#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int L; cin >> L;
	long double x = (long double)L / 3.0;

	printf("%.10Lf\n", x * x * x);

	return 0;
}