#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int n;
vector<char> v;
void dfs(int i, char mx)
{
	char j = 'a';
	while(j <= 'z')
	{
		if (j > mx + 1 || i == 0 && j >= 'b') return;
		v[i] = j;
		if (i == n - 1)
		{
			rep(i, n) cout << v[i];
			cout << endl;
		}
		else
		{
			if (mx < v[i])
				dfs(i + 1, v[i]);
			else
				dfs(i + 1, mx);
		}
		j++;
	}
}

signed main(void)
{
	cin >> n;
	v = vector<char>(n);
	dfs(0, 'a');
	return 0;
}
