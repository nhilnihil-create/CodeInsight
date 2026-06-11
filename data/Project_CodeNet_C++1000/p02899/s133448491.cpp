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
struct input {
	int a, index;
}inp[N];
bool cmp(input a, input b) {
	return a.a < b.a;
}
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inp[i].a;
		inp[i].index = i;
	}
	sort(inp + 1, inp + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		cout << inp[i].index << " ";
	}
	return 0;
}