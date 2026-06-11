#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;

bool sq(int n) {
	bool f = 0;
	for (int i = 0; i < sqrt(n) + 1; i++) {
		if (n == i * i)f = 1;
	}
	return f;
}
int main() {
	int n, d;
	int ans = 0;
	cin >> n >> d;
	vector<vector<int>> x(n, vector<int>(d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> x.at(i).at(j);
		}
	}
	int a=0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = 0; k < d; k++) {
				
				a +=( x.at(i).at(k) -x.at(j).at(k))* (x.at(i).at(k) - x.at(j).at(k));
				
			}
			if (i != j && sq(a) == 1)ans++;
			a = 0;
		}
	}
	cout << ans << endl;
}