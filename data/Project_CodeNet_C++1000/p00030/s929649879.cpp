#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<deque>
#include<list>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

/*
0 1 2 3 4 5 6 7 8 9

*/

//int a(int n, int s, int f) {
//	int cnt = 0;
//	if (n > 2)
//		for (int i = f; i <= 9; i++) {
//			if (s - i > i)cnt += a(n - 1, s - i, i + 1);
//			else break;
//		}
//	else if (n == 2)
//		for (int i = f; i <= 9; i++) {
//			if (s - i <= 9 && s - i > i)cnt++;
//			else break;
//		}
//	else
//		cnt = 1;
//
//	return cnt;
//}

int a, S;

void dfs(int i, int s, int n) {
	//cout << i << " " << s << " " << n << endl;
	if (s == S&&n == 0) {
		a++;
		return;
	}
	if (i == 10 || n == 0)
		return;

	dfs(i + 1, s + i, n - 1);
	dfs(i + 1, s, n);
}

int main() {
	for (int n; cin >> n >> S && (n || S);) {
		a = 0;
		dfs(0, 0, n);
		cout << a << endl;
	}

	return 0;
}