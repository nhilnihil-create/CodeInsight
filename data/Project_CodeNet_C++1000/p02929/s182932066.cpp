#include <bits/stdc++.h>
#define MODD 1000000007
using namespace std;
long long fac(int n)
{
	long long ans = 1;
	for (int i = 2; i <= n; i++) {
		ans = (ans * i) % MODD;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	int d[200005]; // 0 represents L, 1 represents R
	int l[200005] = {0}, r[200005] = {0}; // size should be 2N
	int len = s.size(); 
	d[0] = 0;
	for (int i = 1; i < len; i++) {
		if (s[i] == s[i - 1])
			d[i] = !d[i - 1];
		else
			d[i] = d[i - 1];
	}
	int cntL = 0, cntR = 0;
	for (int i = 0; i < len; i++) {
		if (d[i] == 0)
			cntL++;
		else
			cntR++;
	}
	long long ans = 1;
	if (cntL != cntR || s[0] == 'W' || s[len - 1] == 'W') {
		ans = 0;	
	} else {
		for (int i = 1; i < len; i++) {
			if (d[i - 1] == 0) {
				l[i] = l[i - 1] + 1;
				r[i] = r[i - 1];
			} else {
				l[i] = l[i - 1];
				r[i] = r[i - 1] + 1;
			}
		}
		for (int i = 0; i < len; i++) {
			if (d[i] == 1) {
				ans = (ans * (l[i] - r[i])) % MODD;
			}
		}
		ans = (ans * fac(n)) % MODD;
	}
	cout << ans << endl;
	return 0;
}