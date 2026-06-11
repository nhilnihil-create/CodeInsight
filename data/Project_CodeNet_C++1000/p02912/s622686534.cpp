#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int n, m, i;
	long long sum = 0;
	scanf("%d%d",&n, &m);
	priority_queue<int> q;
	for (i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	while (m--)
	{
		int x = q.top();
		q.pop();
		q.push(x / 2);
	}
	while (!q.empty())
	{
		sum += q.top();
		q.pop();
	}
	cout << sum << endl;
	return 0;
}

