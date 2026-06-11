#include <iostream>
#include <cstring>
using namespace std;
char s[100000000];
int main()
{
	int n, m, i, j, k;
	char a[80], b[80], c;
	bool f = false;
	while (cin >> n && n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i];
		}
		cin >> m;
		strcpy(s, "");
		for (i = k = 0; i < m; i++)
		{
			cin >> c;
			for (j = f = 0; j < n && !f; j++)
			{
				if (c == a[j])
				{
					s[i] = b[j];
					f = true;
				}
			}
			if (!f)
				s[i] = c;
		}
		s[m] = '\0';
		cout << s << endl;
	}
	return 0;
}