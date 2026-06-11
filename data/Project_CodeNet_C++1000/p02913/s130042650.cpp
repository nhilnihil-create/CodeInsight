#include<bits/stdc++.h>
#define for0(i, n) for(int i = 0; i < (n); i++)
using namespace std;
int n, ans; string s;
int main() {
	cin >> n >> s;
	for0(i, n)for0(j, i) {
		if (i - j < ans)continue;
		if (j > 0 && s[i - 1] == s[j - 1])continue;
		int p = j, q = i;
		while (s[p] == s[q]) {
			p++; q++;
			if (p == i)break;
			if (q == n)break;
		}
		ans = max(ans, p - j);
	}
	cout << ans << endl;
}
