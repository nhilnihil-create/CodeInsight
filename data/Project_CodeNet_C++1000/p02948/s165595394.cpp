#include <bits/stdc++.h>

using namespace std;

vector <int> v[100001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int res = 0;
	int n,m,a,b;
	priority_queue <int> pque;

	cin >> n >> m;

	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		if(m-a>=0)
		{
			v[m-a].push_back(b);
		}
	}

	for(int i=m-1;i>=0;i--)
	{
		for(auto it : v[i])
		{
			pque.push(it);
		}
		if(!pque.empty())
		{
			res += pque.top();
			pque.pop();
		}
	}

	cout << res << '\n';
	return 0;
}