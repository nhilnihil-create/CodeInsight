#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	map<int, int> mp;
	rep(i,n) mp[v[i]]++;

	if (mp.size() == 2) {
		bool b1 = false;
		bool b2 = true;
		for (auto p: mp) {
			if (p.first == 0) b1 = true;
			if (p.second != n * 2 / 3 && p.second != n / 3) b2 = false;
		}
		if (b1 && b2 && n % 3 == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	if (mp.size() == 3) {
		bool b = true;
		int x = 0;
		for (auto p: mp) {
			x ^= p.first;
			if (p.second != n / 3) b = false;
		}
		if (b && !x && n % 3 == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	if (mp.size() == 1) {
		if (mp[0] == n) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}