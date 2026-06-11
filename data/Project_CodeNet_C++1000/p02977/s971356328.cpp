#include <cstdio>

inline int lbit(int x) {return x & -x;}
inline void put(int x, int y) {printf("%d %d\n", x, y);}

int main() {
	int n;
	scanf("%d", &n);
	
	if(n == lbit(n)) return puts("No"), 0;
	
	puts("Yes");
	put(3, n+1);
	
	for(int i = 2; i < n - (~n&1); i += 2) {
		put(i, i+1);
		put(i, 1);
		put(i+n+1, 1);
		put(i+n, i+n+1);
	}
	
	if(~n&1) {
		int x = lbit(n), y = n ^ x;
		put(n, x);
		put(n+n, y+n+1);
	}
	return 0;
}