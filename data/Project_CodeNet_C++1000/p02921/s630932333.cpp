#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;

int main() {
	string s, t;
	cin >> s >> t;
	int ans = 0;
	rep(i, 3) {
		if (s[i] == t[i]) ans++;
	}
	cout << ans << endl;
}