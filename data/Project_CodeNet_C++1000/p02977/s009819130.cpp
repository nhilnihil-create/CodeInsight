#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, k, i;
	scanf("%d", &N);
	for(k = 1; k < N; k <<= 1);
	if(k == N){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	k >>= 1;
	if(N == 3){
		printf("1 2\n");
		printf("2 3\n");
		printf("3 4\n");
		printf("4 5\n");
		printf("5 6\n");
		return 0;
	}
	vector<int> a(N + 1);
	for(i = 1; i < k; i++){
		a[i] = i;
	}
	swap(a[2], a[3]);
	for(i = 1; i < k - 1; i++){
		printf("%d %d\n", a[i], a[i + 1]);
		printf("%d %d\n", a[i] + N, a[i + 1] + N);
	}
	printf("%d %d\n", a[k - 1], 1 + N);
	for(i = N; i > k; i -= 2){
		int x = i, y = i - 1;
		printf("%d %d\n", x, y);
		printf("%d %d\n", x + N, y + N);
		printf("%d %d\n", x, x ^ y);
		printf("%d %d\n", y + N, x ^ y);
	}
	if(N % 2 == 0){
		printf("%d %d\n", 1, k);
		printf("%d %d\n", k + 2, k + N);
	}
	return 0;
}