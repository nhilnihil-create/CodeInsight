#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<functional>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
#include <stack>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main() {
	int n, a, ans=-1;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int a = i * 1.08;
		if (a == n)ans = i;
	}
	if (ans == -1)cout << ":(" << endl;
	else cout << ans << endl;
}