#include<bits/stdc++.h>
typedef long long ll;
inline ll read() {ll x = 0;char ch = getchar(), w = 1;while(ch < '0' || ch > '9') {
if(ch == '-') w = -1;ch = getchar();}while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();
}return x * w;}
void write(ll x) {if(x < 0) putchar('-'), x = -x;if(x > 9) write(x / 10);putchar(x % 10 + '0');}
inline void writeln(ll x) {write(x);puts("");}
using namespace std;

int n;
int main() {
	n = read();
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			int x = i ^ j;
			int c = 0;
			while(!(x & (1 << c))) ++c;
			printf("%d ", c + 1);
		}
		puts("");
	}
	return 0;
}
