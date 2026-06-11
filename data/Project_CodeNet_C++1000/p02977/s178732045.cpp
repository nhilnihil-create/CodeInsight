#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int n, D[101000], Old[101000];
vector<pii>OO[101000];
void Add(int a, int b) {
	printf("%d %d\n", a, b);
}
int main() {
	int i, j, k;
	scanf("%d", &n);
	int sz = 1;
	while (sz < n)sz *= 2;
	if (sz == n) {
		puts("No");
		return 0;
	}
	puts("Yes");
	Add(1, 2);
	Add(2, 3);
	Add(3, n+1);
	Add(n+1, n+2);
	Add(n+2, n+3);

	for (i = 4; i < n; i += 2) {
		Add(i, i + 1);
		Add(i + 1, n + 1);
		Add(n + 1, n + i);
		Add(n + i, n + i + 1);
	}
	if (n % 2 == 0) {
		Add(n - 1, n);
		Add(n + (n ^ (n - 1) ^ 1), n + n);
	}
	
}