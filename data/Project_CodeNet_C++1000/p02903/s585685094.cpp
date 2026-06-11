#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
#ifdef LOACL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, M, A, B;
	scanf("%d %d %d %d", &N, &M, &A, &B);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++)
			if((i <= B && j <= A) || (i > B && j > A))
				putchar('1');
			else putchar('0');
		putchar('\n');
	}
	return 0;
}
