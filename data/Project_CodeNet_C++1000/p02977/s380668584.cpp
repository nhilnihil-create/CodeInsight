#include <iostream>
#include <cstdio>
using namespace std;
#pragma warning (disable:4996)
const int maxn = 100005;
int a[maxn << 1], b[maxn << 1];
bool check(int n) {
	n--;
	while (n)
	{
		if (n & 1)
			n >>= 1;
		else
			return true;
	}
	return false;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n == 1 || !check(n)) {
		printf("No\n");
		return 0;
	}
	a[1] = 1; b[1] = 2;
	int size;
	if(n&1){
		size = 1;
		for (int i = 2; i <= n; i += 2) {
			a[++size] = i; b[size] = i + 1;
			a[++size] = i + 1; b[size] = n + 1;
			a[++size] = n + 1; b[size] = n + i;
			a[++size] = n + i; b[size] = n + i + 1;
		}
	}
	else
	{
		size = 1;
		for (int i = 2; i + 1 <= n; i += 2) {
			a[++size] = i; b[size] = i + 1;
			a[++size] = i + 1; b[size] = n + 1;
			a[++size] = n + 1; b[size] = n + i;
			a[++size] = n + i; b[size] = n + i + 1;
		}
		a[++size] = n; b[size] = n - 1;
		a[++size] = n + n; b[size] = (n ^ (n - 1) ^ 1) + n;
	}
	printf("Yes\n");
	for (int i = 1; i <= size; i++) {
		printf("%d %d\n", a[i], b[i]);
	}
}