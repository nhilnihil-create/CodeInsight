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

int M, D, ans = 0;

int main(){
	getint(M), getint(D);
	for(register int m = 1; m <= M; m++)
		for(register int d = 1; d <= D; d++){
			const int d1 = d % 10, d10 = d / 10;
			if(d1 >= 2 && d10 >= 2 && d1 * d10 == m) ans++;
		}
	return printf("%d\n", ans), 0;
}