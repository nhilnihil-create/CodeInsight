#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;



int main() {
	int n, d;
	cin >> n >> d;

	vector<vector<int>> x(n, vector<int>(d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> x[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < d; k++) {
				int num = x[i][k] - x[j][k];
				sum += num * num;
			}

			for (int k = 0; k * k <= sum; k++) {
				if (k * k == sum) {
					cnt++;
				}
			}
			
		}


	}

	cout << cnt << endl;
}
