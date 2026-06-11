#include <bits/stdc++.h>
using namespace std;

int N, M, Q, ans = 0;
vector<int> a(0), b(0), c(0), d(0);
vector<int> A(0);

bool next(){
//	printf("test2\n");
//	printf("(%d, %d, %d)\n", N, M, Q);
	int i, j;
	for(i = N - 1; i >= 0; i--){
//		printf("test3:%d\n", A[i]);
		if(A[i] < M){
//			printf("test4\n");
			A[i]++;
			for(j = i + 1; j < N; j++){
				A[j] = A[i];
			}
			return true;
		}
	}
	return false;
}

signed main(){
	int i;
	scanf("%d%d%d", &N, &M, &Q);
	a.assign(Q, 0);
	b.assign(Q, 0);
	c.assign(Q, 0);
	d.assign(Q, 0);
	for(i = 0; i < Q; i++){
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		a[i]--;
		b[i]--;
	}
	A.assign(N, 1);
	do{
/*		printf("A:");
		for(i = 0; i < N; i++){
			printf("%d ", A[i]);
		}
		printf("\n");
*/		int sum = 0;
		for(i = 0; i < Q; i++){
			if(A[b[i]] - A[a[i]] == c[i]){
				sum += d[i];
			}
		}
//		printf("sum = %d\n", sum);
		ans = max(ans, sum);
	}while(next());
	printf("%d\n", ans);
	return 0;
}