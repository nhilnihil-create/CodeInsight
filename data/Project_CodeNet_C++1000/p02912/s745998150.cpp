// https://atcoder.jp/contests/abc141/tasks/abc141_d
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <deque>
#include <stdio.h>
#include <string>
#include <queue>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	priority_queue<ll> pque;
	int n, m;
	ll a;
	ll sum;
	sum = 0;
	cin >> n >> m;
	rep(i, n) {
		cin >> a;
		pque.push(a);
	}
	// priority queueの最大値を取り出して割る2をして元に戻す
	while (m != 0) {
		ll aTmp;
		aTmp = pque.top()/2;
		// 最大値を削除
		pque.pop();
		pque.push(aTmp);
		m--;
	}
	while (!pque.empty()) {
		sum += pque.top();
		pque.pop();
	}
	cout << sum << endl;
	return 0;
}