#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int n, x=0, m;
set<int>s1, s2, s3;
vector<int>v;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	x = 0;
	for (int i = 0; i < m; i++)
		x += v[i];
	cout << x;
}