#define alphanso                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
int main()
{
	alphanso;
	int n, i, flag = 0;
	cin >> n;
	vector<int> v(n), s(n);
	for (auto &it : v)
		cin >> it;
	s = v;
	sort(s.begin(), s.end());
	for (i = 0; i < v.size(); i++)
	{
		if (v[i] != s[i])
			flag++;
	}
	flag <= 2 ? cout << "YES" : cout << "NO";
	return 0;
}