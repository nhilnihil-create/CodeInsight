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
	int H, W, N; cin >> H >> W >> N;
	cout << (N + max(H, W)-1) / max(H, W) << endl;
}
