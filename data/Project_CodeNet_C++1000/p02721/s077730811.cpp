#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, k, c, dp[222222];
	string s;
	vector<int> v;
	cin >> n >> k >> c >> s;
	dp[0] = 0;
	for (i = 1; i <= n; i++)
	{
		if(s[i-1]=='o'){
			if(i-c-1<0)
				dp[i] = 1;
			else
				dp[i] = dp[i - c - 1] + 1;
		}
		else
			dp[i] = dp[i - 1];
	}
	i = n;
	while(s[i-1]=='x')
		i--;
	while (k > 0)
	{
		int p = i;
		i--;
		while (s[i - 1] == 'x' && i > 1)
			i--;
		if(dp[i]<k)
			v.push_back(p);
		while((i+c>=p||s[i-1]=='x') && i > 1)
			i--;
		k--;
	}
	sort(v.begin(), v.end());
	for(auto &e:v)
		cout << e << endl;
}