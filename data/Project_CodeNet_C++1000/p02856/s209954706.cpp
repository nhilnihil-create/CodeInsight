#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll M; cin >> M;
	ll tot = 0, keta = 0;
	for (int i = 0; i < M; i++) {
		ll d, c; cin >> d >> c;
		tot += d * c;
		keta += c;
	}
	cout << (tot - 1) / 9 + keta - 1 << endl;
}
