#include <bits/stdc++.h>

using namespace std;

int main() {
	long long x;
	scanf("%lld", &x);
	
	long long cur = 100;
	int cnt = 0;
	
	while (cur < x) {
		cur = cur + cur / 100;
		cnt++;
	}
	
	printf("%d\n", cnt);
}
