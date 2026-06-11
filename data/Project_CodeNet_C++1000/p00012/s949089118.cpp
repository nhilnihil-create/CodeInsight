#include "bits/stdc++.h"

#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef long long ll;

bool isAbove(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
	if (p1.first == p2.first) {
		return p3.first > p1.first;
	} else {
		return p3.second > p1.second + (p2.second - p1.second) * (p3.first - p1.first) / (p2.first - p1.first);
	}
}

void solve() {
#ifdef _WIN32
	istream &cin = ifstream("input.txt");
#endif

	vector<pair<double, double>> vertices(4);
	while (cin >> vertices[0].first) {
		cin >> vertices[0].second;
		rep(i, 3) cin >> vertices[i + 1].first >> vertices[i + 1].second;

		bool flag = (isAbove(vertices[0], vertices[1], vertices[2]) == isAbove(vertices[0], vertices[1], vertices[3]));
		flag &= (isAbove(vertices[0], vertices[2], vertices[1]) == isAbove(vertices[0], vertices[2], vertices[3]));
		flag &= (isAbove(vertices[1], vertices[2], vertices[0]) == isAbove(vertices[1], vertices[2], vertices[3]));

		cout << (flag ? "YES" : "NO") << endl;
	}


}




int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	solve();
	return 0;
}