#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <cassert>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int N, M,ans;
	scanf("%d%d", &N, &M);
	ans = M * 10;
	rep(i, 20) {
		if ((ans) * 8 / 100 == N && (ans) / 10 == M) {
			printf("%d", ans);
			return 0;
		}
		ans++;
	}
	printf("-1");
}