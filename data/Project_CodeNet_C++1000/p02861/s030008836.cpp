#include<bits//stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
ll n, m, x = 0, y,z,w,h, sum= 0, ans = 0;ld s = 0;
int main() {
	cin >> n; vector<pair<int,int>> a(n);vector<int> b(n);
	rep(i, n) {cin >> x >> y;a[i] = { x,y };b[i] = i;}
	do {
		rep(i, n - 1) {
			s += sqrt(pow(a[b[i]].first - a[b[i + 1]].first, 2) + pow(a[b[i]].second - a[b[i + 1]].second, 2));
		}sum++;
	} while (next_permutation(ALL(b)));
	cout << fixed << setprecision(10) << (ld)s / sum << endl;
}