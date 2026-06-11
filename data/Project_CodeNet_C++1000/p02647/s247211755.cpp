#include <bits/stdc++.h>
using namespace std;

const int maxN = 200010;

int A[2][maxN];

int main (){
	int n, k, i, j, p;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; ++i) scanf("%d", A[0] + i);
	for(p = 0; p < k; ++p){
		int cur = p & 1, nxt = 1 - cur;
		for(i = 0; i < n; ++i)
			if(A[cur][i] != n) break;
		if(i == n) break;
		for(i = 0; i < n; ++i) A[nxt][i] = 0;
		for(i = 0; i < n; ++i){
			if(i < A[cur][i]) ++A[nxt][0];
			else ++A[nxt][i - A[cur][i]];
if(i + A[cur][i] + 1 < n)
			--A[nxt][i + A[cur][i] + 1];
		}
		for(i = 0; i < n; ++i) A[nxt][i] += A[nxt][i - 1];
	}
	for(i = 0; i < n; ++i) printf("%d ", p < k ? n : A[k & 1][i]);
	return 0;
}