#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int x, y, s;
	while (cin >> x >> y >> s && x != 0 && y != 0 && s != 0)
	{
		int MAX = 0;
		for (int i = 1; i < s; i++)
		{
			int beforeI = i * (x + 100) / 100;
			for (int j = 1 ; j < s; j++)
			{
				int beforeJ = j * (x + 100) / 100;
				if (beforeI + beforeJ == s)
				{
					int afterI = (i * (y + 100)) / 100;
					int afterJ = (j * (y + 100)) / 100;
					MAX = max(MAX,afterI + afterJ);
					break;
				}
			}
		}

		cout << MAX << endl;
	}
	return 0;
}