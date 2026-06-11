#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
#define N 100009
#define LL long long
#define INF 0x7fffffff
#define mymin(x,y) (x>=y?y:x)
#define mymax(x,y) (x>=y?x:y)
LL input[N], out[N];
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	LL n;
	LL sum = 0;
	cin >> n;
	for (LL i = 1; i <= n; i++) {
		cin >> input[i % n];
		sum += input[i % n];
	}
	out[1] = 0;
	for (LL i = 0; i < n; i++) {
		out[(i * 2 + 1 + 2) % n] = out[(i * 2 + 1) % n]
			+ (input[(i * 2 + 2) % n] - input[(i * 2 + 1) % n]) * 2;
	}
	for (LL i = 0; i < n; i++) {
		sum -= out[i];
	}
	for (LL i = 0; i < n; i++) {
		out[i] += (sum / n);
	}
	for (LL i = 1; i <= n; i++) {
		cout << out[i % n] << " ";
	}
	return 0;
}