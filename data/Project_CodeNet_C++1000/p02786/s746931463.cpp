#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	long long H;
	scanf("%lld", &H);
	long long ans = 0;
	long long monsterNum = 1;
	while (H > 0) {
		if (H == 1) {
			ans += monsterNum;
			H = 0;
		} else {
			ans += monsterNum;
			H /= 2;
			monsterNum *= 2;
		}
	}
	printf("%lld\n", ans);

	return 0;
}
