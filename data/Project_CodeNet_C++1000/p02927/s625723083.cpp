#include <cstdio>
#include <iostream>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
inline char nc() {
	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++; 
}
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
int M, D;
int solve() {
	int cnt = 0;
	for(int i = 2; i <= 9; ++i) {
		for(int j = 2; j <= 9; ++j) {
			if(i * 10 + j > D) continue;
			if(i * j <= M) {
//				debug("%d %d\n", i, j); 
				++cnt;
			} 
		}
	}
	return cnt;
}
int main() {
	read(M), read(D);
	printf("%d\n", solve());
	return 0;
} 