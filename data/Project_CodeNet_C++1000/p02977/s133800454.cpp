/*
	构造
	n为2的幂时显然无解 
	发现n大于3并且为奇数时很容易可以构造出一组解 
	每次增加两个时，两两配对即可
	如果最后还剩一个数也可以很容易配出来 
*/
#include <bits/stdc++.h>

using namespace std;

int n;

inline void link(int u, int v) {
	printf("%d %d\n", u, v);
}

int main() {
	scanf("%d", &n);
	if(n < 3 || (n & -n) == n) {
		puts("No");
	} else {
		puts("Yes");
		link(1, 2);
		link(2, 3);
		link(3, 1 + n);
		link(1 + n, 2 + n);
		link(2 + n, 3 + n);
		for(int i = 4; i < n; i += 2) {
			link(1, i);
			link(i, i + 1);
			link(1, i + 1 + n);
			link(i + 1 + n, i + n);
		}
		if(~n & 1) {
			int x = n;
			x ^= 1;
			for(int i = 2; i <= n; ++i) {
				int r = x ^ i;			
				if(r != 1 && r < n) {
					link(n, (i & 1 ? i + n : i));
					link(n + n, (r & 1 ? r + n : r));
					break;
				}
			}
		}
	}
	return 0;
}