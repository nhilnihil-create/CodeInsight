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

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N, A, B;
	cin >> N >> A >> B;

	if ((B - A) % 2 == 0) cout << (B - A) / 2 << endl;
	else {
		ll ans1, ans2;
		ans1 = A + (B - A) / 2;
		ans2 = (N - B + 1) + (B - A - 1) / 2;
		cout << min(ans1, ans2) << endl;
	}
}
