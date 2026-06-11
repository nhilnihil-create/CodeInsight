#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int c = 0, ok = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b; cin >> a >> b;
		if (a == b)
		{
			c++;
			if (c == 3)
				ok = 1;
		}
		else
			c = 0;
	}
	cout << (ok ? "Yes" : "No") << endl;
}
