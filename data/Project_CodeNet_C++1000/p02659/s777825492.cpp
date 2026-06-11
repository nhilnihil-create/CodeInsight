#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	long long  n,p;
	while (cin>>n>>s)
	{
		int l = s.length();
		int b, m;
		b = m = -1;
		for (int i = 0; i < l; i++)
		{
			if (s[i] != '0')
			{
				b = i;
				break;
			}
		}
		for (int i = b; i < l; i++)
		{
			if (s[i] == '.')
			{
				m = i;
				break;
			}
		}
		p = 0;
		if (m != -1)
		{
			for (int i = l-1; i > m; i--)
			{
				p = (s[i] - '0') * n + p;
				p = p / 10;
			}
		}
		if (b != -1)
		{
			if (b == m)
				cout << p << endl;
			else
			{
				for (int i = m-1; i >= b; i--)
				{
					p = (s[i] - '0') * n + p;
					s[i] = p % 10;
					p /= 10;
				}
				
				if (p)
				{
					cout << p;
				}
				for (int i = b; i < m; i++)
				{
					cout << (int)s[i];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
