#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		map<string, bool> pattern;
		cin >> str;

		for (int i = 1; i < str.size(); i++)
		{
			string front = str.substr(0, i);
			string back = str.substr(i, str.size() - i);

			pattern[front + back] = true;
			pattern[back + front] = true;

			reverse(front.begin(), front.end());
			pattern[front + back] = true;
			pattern[back + front] = true;

			reverse(back.begin(), back.end());
			pattern[front + back] = true;
			pattern[back + front] = true;

			reverse(front.begin(), front.end());
			pattern[front + back] = true;
			pattern[back + front] = true;
		}

		cout << pattern.size() << endl;
	}

	return 0;
}