#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, a[N];
char s[N];
bool ans;

int main() {
	scanf("%d%s", &n, s), --n;
	for(int i = 0; i <= n; ++i) {
		a[i] = s[i] - '1';
		if((n & i) == i) ans ^= a[i] & 1;
	}
	if(ans) return puts("1"), 0;
	for(int i = 0; i <= n; ++i) {
		if(a[i] & 1) return puts("0"), 0;
		a[i] >>= 1;
	}		
	ans = 0;
	for(int i = 0; i <= n; ++i) 	
		if((n & i) == i) ans ^= a[i] & 1;
	puts(ans ? "2" : "0");
	return 0;
}
