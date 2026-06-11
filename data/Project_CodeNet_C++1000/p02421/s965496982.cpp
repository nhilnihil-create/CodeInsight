#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int taro = 0, hanako = 0;
	while (n--)
	{
		string t, h;
		cin >> t >> h;

		if (t == h)
		{
			taro++, hanako++;
			continue;
		}

		int i = 0;
		while (t[i] || h[i])
		{
			if (t[i] > h[i] || !h[i])
			{
				taro += 3;
				break;
			}
			else if (t[i] < h[i] || !t[i])
			{
				hanako += 3;
				break;
			}

			i++;
		}
	}

	cout << taro << " " << hanako << endl;

	return 0;
}