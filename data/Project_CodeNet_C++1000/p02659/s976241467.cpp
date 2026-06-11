#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int A;
	double B;
	scanf("%lld%lf", &A, &B);
	printf("%lld\n", (A * (int)(B * 100 + 0.1)) / 100);
	return 0;
}