#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s[n];
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
	}
	sort(s, s + n);
	long long res = 0;
	string pre = s[0];
	for (int i = 0; i < n; )
	{
		int j = i + 1;
		long long tmp = 1;
		while (pre == s[j] && j < n)
		{
			j++;
			tmp++;
		}
		res += tmp * (tmp - 1) / 2;
		if(j == n) break;
		pre = s[j];
		i = j;
	}
	cout << res << endl;
	return 0;
}
