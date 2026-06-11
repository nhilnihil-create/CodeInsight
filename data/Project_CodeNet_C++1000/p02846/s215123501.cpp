#include <bits/stdc++.h>

using namespace std;

int main() {
	long long t1, t2, a1, a2, b1, b2;
	scanf("%lld%lld%lld%lld%lld%lld", &t1, &t2, &a1, &a2, &b1, &b2);
	
	long long len1 = t1 * a1 + t2 * a2;
	long long len2 = t1 * b1 + t2 * b2;
	if (len1 == len2) return 0 * printf("infinity\n");
	
	if (len1 > len2) {
		swap(a1, b1);
		swap(a2, b2);
		swap(len1, len2);
	}
	
	//len1 < len2
	
	if (a1 < b1) return 0 * printf("0\n");
	
	//n * len1 + t1 * a1 >= n * len2 + t1 * b1
	//t1 * (a1 - b1) >= n * (len2 - len1)
	//n <= t1 * (a1 - b1) / (len2 - len1)
	
	long long n = t1 * (a1 - b1) / (len2 - len1);
	
	long long res = 0;
	
	if (n * len1 + t1 * a1 == n * len2 + t1 * b1) res = n * 2;
	else res = n * 2 + 1;
	
	printf("%lld\n", res);
}
