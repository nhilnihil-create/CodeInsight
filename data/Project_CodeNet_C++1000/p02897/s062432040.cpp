#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	if (N == 1)cout << 1.000000000 << endl;
	else if (N % 2 == 0)cout << 0.50000000 << endl;
	else cout << (ldb)((N + 1) / 2) / (ldb)N << endl;
}
