#include <bits/stdc++.h>
using namespace std;
int k, a[111], d[100001], n;
int main() {
	for(int i = 1; i <= 100000; i <<= 1) d[i] = 1;
	cin >> n; 
	if(d[n]) {printf("No\n"); return 0;} 
	printf("Yes\n");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n", n + 1, n + 1, n + 2, n + 2, n + 3);
	for(int i = 4; i < n; i += 2){
		printf("%d %d\n", i, 1 + n); printf("%d %d\n", i + 1, 1 + n);
		printf("%d %d\n", i + n, i + 1); printf("%d %d\n", i + n + 1, i);
	}
	if(n % 2 == 0){
		for(int i = 2; i <= n; i++){
			int p = i ^ 1 ^ n;
			if(p < n && p > 1) {
				if(i == 2) printf("%d %d\n", i + n, n);
				else printf("%d %d\n", i, n);
				printf("%d %d\n", p, n + n);
				return 0;
			}
		}
	}
}
