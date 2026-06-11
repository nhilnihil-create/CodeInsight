#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, A[100005];

int main(){
	getint(N);
	for(register int i = 1; i <= N; i++) getint(A[i]);
	for(register int i = 2; i <= N; i++) if(A[i] < A[1]) swap(A[i], A[1]);
	for(register int i = 1; i < N; i++) if(A[i] > A[N]) swap(A[i], A[N]);
	int ans = A[N] - A[1];
	for(register int i = 2; i < N; i++) ans += abs(A[i]);
	printf("%d\n", ans);
	for(register int i = 2; i < N; i++)
		if(A[i] > 0) printf("%d %d\n", A[1], A[i]), A[1] -= A[i];
		else printf("%d %d\n", A[N], A[i]), A[N] -= A[i];
	return printf("%d %d\n", A[N], A[1]), 0;
}
