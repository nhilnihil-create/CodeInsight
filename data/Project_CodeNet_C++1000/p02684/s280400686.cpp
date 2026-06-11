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
#include<time.h>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N, K; cin >> N >> K;
	vector<int> a(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	if (K <= N) {
		int now = 1;
		while (K) {
			now = a[now];
			K--;
		}
		cout << now << endl;
	}

	else {
		vector<int> vi(N + 1);
		vi[1] = 1;
		int now = 1;
		for (ll i = 2; i <= N + 2; i++) {
			now = a[now];
			if (!vi[now]) vi[now] = i;
			else {
				ll T = i - vi[now];
				ll rem = (K - i) % T;
				//cout << "T=" << T << " rem=" << rem << endl;
				for (int j = 0; j <= rem; j++) {
					now = a[now];
				}
				break;
			}
		}

		cout << now << endl;
	}
}
