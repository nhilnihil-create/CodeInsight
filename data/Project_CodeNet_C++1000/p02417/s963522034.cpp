#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int arr[26] = {0};
	while (getline(cin, s))
	{
		for (int i = 0; i < s.length(); i++)
		{
			if(65 <= s[i] && s[i] <= 90)
				arr[s[i] - 65]++;
			else if(97 <= s[i] && s[i] <= 122)
				arr[s[i] - 97]++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << (char)(i+97) << " : " << arr[i] << endl;
	}
	return 0;
}