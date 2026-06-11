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

int N, ans = 1;
char str[200005];

int main(){
	getint(N), scanf("%s", str); int cnt = 1;
	if(str[0] == 'W') return puts("0"), 0;
	for(register int i = 1, cur = 1; i < (N << 1); i++){
		cur ^= str[i] == str[i - 1];
		if(cur) cnt++; else ans = ans * (ll)cnt-- % MOD;
	}
	for(register int i = 1; i <= N; i++) ans = ans * (ll)i % MOD;
	return printf("%d\n", cnt ? 0 : ans), 0;
}