#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

vi a[1005];
int idx[1005];

int main() {
	int n;
	cin >> n;
	rep1(i, n) rep(j, n - 1) {
		int t;
		cin >> t;
		a[i].push_back(t);
	}
	rep1(i, n) idx[i] = 0;
	bool update = true;
	vector<bool> played(n + 1, false);
	int day = 0;
	int games = 0;
	vector<int> v[2];
	rep1(i, n) v[0].push_back(i);
	while(update) {
		update = false;
		fill(played.begin(), played.end(), false);
		v[(day + 1) % 2].clear();
		for(int i : v[day % 2]) {
			if(played[i]) continue;
			if(idx[i] == n - 1) continue;
			int oppo = a[i][idx[i]];
			if(played[oppo]) continue;
			if(a[oppo][idx[oppo]] == i) {
//				cout << day << ' ' << i << ' ' << oppo << endl;
				idx[i]++;
				idx[oppo]++;
				played[i] = true;
				played[oppo] = true;
				games++;
				update = true;
				v[(day + 1) % 2].push_back(i);
				v[(day + 1) % 2].push_back(oppo);
			}
		}
		if(update) day++;
	}
	if(games < n * (n - 1) / 2) {
		cout << -1 << endl;
		return 0;
	}
	cout << day << endl;
}
