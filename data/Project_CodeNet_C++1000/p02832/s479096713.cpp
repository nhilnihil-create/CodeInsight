#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	int p=0;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (p + 1 == a)
			p++;
	}
	if (p)	cout << N -p << endl;
	else cout << -1 << endl;
}