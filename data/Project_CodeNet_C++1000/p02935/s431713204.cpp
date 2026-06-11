#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());

	double ans = a[0];
	rep(i, n - 1) {
		ans = (ans + a[i + 1]) / 2;
	}
	cout << ans << endl;
}
