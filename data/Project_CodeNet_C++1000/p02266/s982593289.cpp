#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<string>
#define lens 10000

using namespace std;
stack<pair<int, int> > S2;
stack<int> S1;
int a[lens];
int main()
{
	char c;
	int i = 0;
	int total = 0;
	while (cin >> c)
	{
		if (c == '\\')
		{
			S1.push(i);
			i++;
			int h = 0;
		}
		else if (c == '/')
		{
			if (S1.size() > 0)
			{
				int t = S1.top();
				S1.pop();
				int a = i - t;
				total += a;
				i++;
				while (S2.size() > 0 && S2.top().first > t)
				{
					int sum = S2.top().second;
					S2.pop();
					a = a + sum;
				}
				S2.push(make_pair(t, a));

			}
		}
		else if (c == '_')
		{
			if (S1.size() > 0)
				i++;
		}
		else if (c == '1')
		{
			break;
		}
	}
	cout << total << endl;
	cout << S2.size();
	int m = S2.size();
	for (int j = 0; j < m; j++)
	{
		a[j]=S2.top().second;
		S2.pop();
	}
	for (int j = m-1; j >= 0 ; j--)
	{
		cout << ' ';
		cout << a[j];
	}
	cout << endl;
	return 0;
}
