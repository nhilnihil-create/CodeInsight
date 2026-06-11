#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	string s; cin >> s;
	string t; cin >> t;
	int cnt = 0;
	rep(i, 3)
	{
		if (s[i] == t[i])
			cnt++;
	}
	cout << cnt << endl;
	return (0);
}
