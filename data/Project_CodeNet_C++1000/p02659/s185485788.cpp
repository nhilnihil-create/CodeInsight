#include <bits/stdc++.h>
long long a, b1, b2;
int main(){
	scanf("%lld %lld.%lld", &a, &b1, &b2);
	printf("%lld\n", a * (b1*100 + b2) / 100);
}