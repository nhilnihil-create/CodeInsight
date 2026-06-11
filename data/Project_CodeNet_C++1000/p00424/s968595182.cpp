#include <iostream>
#include <map>
#include <string>

using namespace std;

int main ( void )
{
	int n;

	while ( cin >> n, n )
	{
		map<char, char> t;

		for (int i = 0; i < n; ++i)
		{
			char a, b;
			cin >> a >> b;
			t[a] = b;
		}

		int m;
		cin >> m;

		string out = "";

		for (int i = 0; i < m; ++i)
		{
			char c;
			cin >> c;
			if ( t.count(c) )
				out += t[c];
			else
				out += c;
		}
		cout << out << endl;
	}

	return 0;
}