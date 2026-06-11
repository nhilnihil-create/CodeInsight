#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int read() {
	int x = 0, f = 1; char ch;
	while(! isdigit(ch = getchar())) (ch == '-') && (f = -f);
	for(x = ch ^ 48; isdigit(ch = getchar()); x = (x << 3) + (x << 1) + (ch ^ 48));
	return x * f;
}
template <class T> T Max(T a, T b) { return a > b ? a : b; }
template <class T> T Min(T a, T b) { return a < b ? a : b; }
int n;
int main() {
	n = read();
	if((n & (n - 1)) == 0) return puts("No"), 0;
	puts("Yes"); puts("1 2"); puts("2 3");
	printf("%d %d\n", 3, n + 1); printf("%d %d\n", n + 1, n + 2); printf("%d %d\n", n + 2, n + 3);
	for(int i = 4, j; i + 1 <= n; i += 2) {
		j = i + 1;
		printf("%d %d\n", 1, i); printf("%d %d\n", i, j + n);
		printf("%d %d\n", 1, j); printf("%d %d\n", j, i + n);
	}
	if(n % 2 == 0) {
		for(int i = 4, j; i <= n; ++ i) {
			j = n ^ i ^ 1;
			if(j == 3 || j >= n) continue;
			printf("%d %d\n", i, n); printf("%d %d\n", j, 2 * n);
			return 0;
		}
	}
	return 0;
}
