#include <bits/stdc++.h>

#define LL long long
#define pa pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 100001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

bool v[N];
int l1, l2, l3, h1[N], h2[N], h3[N];

int main() {
	int n = read();
	int len = 1;
	for(; len <= n / 2; len <<= 1);
	if(len == n) {puts("No"); return 0;}
	puts("Yes");
	int ans = 0, s = 0;
	for(int i = 1; i <= n; i++) ans ^= i;
	if(ans == 0) {
		for(int i = 1; i < 2 * n; i++) put(i), putchar(' '), put(i + 1), puts("");
		return 0;
	} for(int i = 20; i >= 0; i--) if((1 << i) & ans){
		h1[++l1] = (1 << i), v[1 << i] = 1;
		if(ans ^ (1 << i)) h1[++l1] = (ans ^ (1 << i)), v[ans ^ (1 << i)] = 1;
		if(ans != 1) {
			if((1 << i) ^ 1) h2[++l2] = (1 << i) ^ 1, v[(1 << i) ^ 1] = 1;
			if(ans ^ (1 << i) ^ 1) h2[++l2] = ans ^ (1 << i) ^ 1, v[ans ^ (1 << i) ^ 1] = 1;
		} else {
			if((1 << i) ^ 2) h2[++l2] = (1 << i) ^ 2, v[(1 << i) ^ 2] = 1;
			if(ans ^ (1 << i) ^ 2) h2[++l2] = ans ^ (1 << i) ^ 2, v[ans ^ (1 << i) ^ 2] = 1;
		} break;
	} for(int i = 1; i <= n; i++) if(!v[i]) h3[++l3] = i;
	for(int i = 1; i < l2; i++) put(h2[i]), putchar(' '), put(h2[i + 1]), puts("");
	if(l2) put(h2[l2]), putchar(' '), put(h1[1]), puts("");
	for(int i = 1; i < l1; i++) put(h1[i]), putchar(' '), put(h1[i + 1]), puts("");
	if(l2) put(h1[l1]), putchar(' '), put(h2[1] + n), puts("");
	for(int i = 1; i < l2; i++) put(h2[i] + n), putchar(' '), put(h2[i + 1] + n), puts("");
	if(l2) put(h2[l2] + n), putchar(' '), put(h1[1] + n), puts("");
	for(int i = 1; i < l1; i++) put(h1[i] + n), putchar(' '), put(h1[i + 1] + n), puts("");
	for(int i = 1; i < l3; i++) put(h3[i]), putchar(' '), put(h3[i + 1]), puts("");
	if(l3) put(h3[l3]), putchar(' '), put(h1[1]), puts(""), put(h1[l1]), putchar(' '), put(h3[1] + n), puts("");
	for(int i = 1; i < l3; i++) put(h3[i] + n), putchar(' '), put(h3[i + 1] + n), puts("");
	return 0;
}

