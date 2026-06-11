/*https://atcoder.jp/contests/abc142/tasks/abc142_c*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, a;
	cin >> n;
	vector <pair<int , int>> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		v.push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i].second << " ";
}