#include <iostream>
#include <vector>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	int ans = 0;

	for (int i = '0'; i <= '9'; i++)
	{
		for (int j = '0'; j <= '9'; j++)
		{
			for (int k = '0'; k <= '9'; k++)
			{

				int pointer_b = 0;
				bool flaga = false;
				bool flagb = false;
				bool flagc = false;

				for (char &val : s)
				{
					if (pointer_b == 0 && val == i)
					{
						flaga = true;
						pointer_b++;
					}
					else if (pointer_b == 1 && val == j)
					{
						flagb = true;
						pointer_b++;
					}
					else if (pointer_b == 2 && val == k)
					{
						flagc = true;
						pointer_b++;
					}

					if (flaga && flagb && flagc)
					{
						ans++;
						break;
					}
				}
			}
		}
	}

	cout << ans << endl;
}
//g++ -std=c++17 -g main.cpp -o mai	n