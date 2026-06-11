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
	map<string, ll> m;
	vector<string> a;
	rep(i, n) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		m[s]++;
		if (m[s] == 1) a.push_back(s);
	}
	ll ans = 0;
	rep(i, a.size()) {
		ll ni = m[a[i]];
		ans += ni * (ni - 1) / 2;
	}
	cout << ans << endl;
}