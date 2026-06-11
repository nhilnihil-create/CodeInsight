#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B;
	scanf("%d%d", &A, &B);
	printf("%d\n", max(0, A - 2 * B));
	return 0;
}