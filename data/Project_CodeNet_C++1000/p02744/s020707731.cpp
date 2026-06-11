#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 10000000000000000;
const int mod = 1000000007;
string s[123456]; int g = 1;
void G(int n) {
	for (int a = 1; a < n; a++) {
		int kari = g;
		for (int h = 0; h < kari; h++) {
			int saidai = 0;
			for (int i = 0; i < s[h].size(); i++) {
				saidai = max(saidai, (int)(s[h][i] - 97));
			}
			for (int i = 0; i <= saidai; i++) {
				s[g] = s[h] + (char)(98 + i); g++;
			}
			s[h] += "a";
		}
	}
}
int iti[12345678], cnt[12345678], cost[4321][4321];
signed main() {
	int n, m, a = 140, b = 170, cnt = 30, ans = 0;
	cin >> n; s[0] = "a"; G(n); sort(s, s + g);
	for (int h = 0; h < g; h++) {
		cout << s[h] << endl;
	}
	cin >> n; return 0;
}