#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	rep(i, 1000) {
		int c[3] = {i/100, (i%100)/10, i%10};
		int f = 0;
		rep(i, n) {
			if (s[i] == '0'+c[f]) f++;
			if (f == 3) {cnt++; break;}
		}
	}

	cout << cnt << endl;
	return 0;
}