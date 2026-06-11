#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string n, t;
	int cnt;
	while (cin >> t)
	{
		if (t[0] == '-')
			break;
		
		if (isdigit(t[0]))
		{
			cnt = atoi(t.c_str());
			
			for (int i = 0; i < cnt; i++)
			{
				cin >> t;
				int h = atoi(t.c_str());
				n = n.substr(h) + n.substr(0, h);
			}
			cout << n << endl;
		}
		else
		{
			n = t;
			continue;
		}
	}
	
	return 0;
	
}