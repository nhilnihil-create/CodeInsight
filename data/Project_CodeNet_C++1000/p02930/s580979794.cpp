#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, a[505][505];

void calc(const int &l, const int &r, const int &col){
	if(l == r) return; const int mid = l + r >> 1;
	for(register int i = l; i <= mid; i++)
		for(register int j = mid + 1; j <= r; j++) a[i][j] = col;
	calc(l, mid, col + 1), calc(mid + 1, r, col + 1);
}

int main(){
	getint(N), calc(1, N, 1);
	for(register int i = 1; i <= N; i++, puts(""))
		for(register int j = i + 1; j <= N; j++) printf("%d ", a[i][j]);
	return 0;
}