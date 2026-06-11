#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	int ans = 0;
	rep(i, n - 2) {
		vector<int> a(3);
		rep(j, 3) a[j] = p[i + j];
		sort(a.begin(), a.end());
		if (a[1] == p[i + 1]) ans++;
	}
	cout << ans << endl;
}