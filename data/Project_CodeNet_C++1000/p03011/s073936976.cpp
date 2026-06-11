#include <bits/stdc++.h>
using namespace std;

signed main(){
	int P, Q, R;
	scanf("%d%d%d", &P, &Q, &R);
	printf("%d\n", P + Q + R - max({P, Q, R}));
	return 0;
}