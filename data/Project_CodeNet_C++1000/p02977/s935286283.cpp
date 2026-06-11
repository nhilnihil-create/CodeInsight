#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <algorithm>
#define lowbit(i)((i)&(-i))
template <typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-')	flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
int n;
int main() {
	read(n);
	if (n == lowbit(n)) {
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n", n + 1, n + 1, n + 2, n + 2, n + 3);
	for (register int i = 4; i < n; i += 2) {
		printf("1 %d\n", i);
		printf("1 %d\n", i + 1);
		printf("%d %d\n", i + 1, n + i);
		printf("%d %d\n", i, n + i + 1);
	}
	if (!(n & 1)) {
		for (register int i = 4; i < n; ++i) {
			if ((n ^ 1 ^ i) != 3 && (n ^ 1 ^ i) < n) {
				printf("%d %d\n", i, n);
				printf("%d %d\n", n ^ 1 ^ i, (n << 1));
				return 0;
			}
		}
	}
	return 0;
}

