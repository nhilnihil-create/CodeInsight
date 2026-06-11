#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define x_ real()
#define y_ imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
pair<int, int> dirs[] = { {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };
const ld eps = 1e-6;
const int N = 1e5 + 7;


int main() {
	fastIO;
	int n;
	cin >> n;
	vector<int> v, s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	s = v;
	sort(s.begin(), s.end());
	if (v == s) {
		cout << "YES";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			swap(v[i], v[j]);
			if (v == s) {
				cout << "YES";
				return 0;
			}
			swap(v[i], v[j]);
		}
	}
	cout << "NO";

}
