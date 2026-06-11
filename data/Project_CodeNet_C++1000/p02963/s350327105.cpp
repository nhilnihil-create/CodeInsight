#include<bits/stdc++.h>
using namespace std;
long long S;

int main() {
	scanf("%lld", &S);
	long long x = (S + 999999999) / 1000000000;
	long long y = x * 1000000000 - S;
	printf("0 0 1 1000000000 %lld %lld\n", x, y);
	return 0;
}