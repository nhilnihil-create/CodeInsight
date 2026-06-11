#include <bits/stdc++.h>
using namespace std;

void getPerms(int index, int limit, vector<string>& v, vector<int>& visited, string cur)
{
	if(index == limit)
	{
		v.push_back(cur);
		return;
	}

	for(int i = 0; i < limit; ++i)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			getPerms(index+1, limit, v, visited, cur + to_string(i+1));
			visited[i] = 0;
		}
	}
}

int main()
{
	int n; cin >> n;
	vector<string> v;
	vector<int> visited(n+1, 0);
	getPerms(0, n, v, visited, "");
	string p = "";
	for(int i = 0; i < n; ++i)
	{
		int num; cin >> num; p += to_string(num);
	}
	string q = "";
	for(int i = 0; i < n; ++i)
	{
		int num; cin >> num; q += to_string(num);
	}
	auto p1 = find(v.begin(), v.end(), p) - v.begin();
	auto p2 = find(v.begin(), v.end(), q) - v.begin();
	cout << abs(p1-p2);
	return 0;
}