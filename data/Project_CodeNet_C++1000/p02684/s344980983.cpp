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
	vector<vector<int>> dou(N + 1,vector<int>(64));
	for (int i = 1; i <= N; i++) {
		cin >> dou[i][0];
	}

	for (int i = 0; i < 63; i++) {
		for (int j = 1; j <= N; j++) {
			dou[j][i + 1] = dou[dou[j][i]][i];
		}
	}

	int now = 1;
	for(int i=0;i<64;i++){
		if (K % 2) {
			now = dou[now][i];
		}
		K /= 2;
		if (K == 0)break;
	}

	cout << now << endl;
}
