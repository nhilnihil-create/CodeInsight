#include <cstdio>
using namespace std;

int mdb(int a, int b) {
	int c = a ^ b;
	if(c == 0) return 32;
	int ans = 0;
	for(; !(c & 1); ans++) {
		c /= 2;
	}
	return ans;
}

int main() {
	int N;
	scanf("%d%*c", &N);
	for(int i = 0; i < N - 1; i++) {
		for(int j = i + 1; j < N; j++) {
			printf("%d", mdb(i, j) + 1);
			if(j < N - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
