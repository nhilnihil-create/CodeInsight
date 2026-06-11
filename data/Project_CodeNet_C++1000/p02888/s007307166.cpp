#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
#define N 2009
#define LL long long
#define INF 0x7fffffff
#define mymin(x,y) (x>=y?y:x)
#define mymax(x,y) (x>=y?x:y)
int input[N], tong[N], tong2[N], two[N][N];
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	memset(tong, 0, sizeof(tong));
	memset(tong2, 0, sizeof(tong2));
	memset(two, 0, sizeof(two));
	int n, a, index = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		input[index++] = a;
		tong[a]++;
		tong2[a] = 1;
	}
	for (int i = 1; i < N; i++) {
		//tong[i] += tong[i - 1];
		tong[i] += tong[i - 1];
	}
	sort(input, input + index);
	int decr = 1;
	for (int j = input[0]; j < N; j++) {
		two[0][j] = tong[j] - tong[input[0] - 1] - decr;
	}
	for (int i = 1; i <= index; i++) {
		if (input[i] == input[i - 1])
			decr++;
		else
			decr = 1;
		for (int j = input[i]; j < N; j++) {
			two[i][j] = tong[j] - tong[input[i] - 1] - decr;
		}
	}
	for (int i = 0; i < index; i++) {
		for (int j = i + 1; j < index - 1; j++) {
			ans += two[j][input[i] + input[j] - 1];
		}
	}
	cout << ans;
	return 0;
}