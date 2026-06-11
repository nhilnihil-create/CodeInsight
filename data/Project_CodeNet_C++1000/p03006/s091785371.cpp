#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, x[55], y[55], ans;

int main(){
	getint(N), ans = N;
	for(register int i = 1; i <= N; i++) getint(x[i]), getint(y[i]);
	for(register int i = 1; i <= N; i++)
		for(register int j = i + 1; j <= N; j++){
			const int dx = x[i] - x[j], dy = y[i] - y[j]; int res = 0;
			for(register int k = 1; k <= N; k++)
				for(register int l = 1; l <= N; l++)
					if(x[k] - x[l] == dx && y[k] - y[l] == dy) {res++; break;}
			ans = min(ans, N - res);
		}
	return printf("%d\n", ans), 0;
}
