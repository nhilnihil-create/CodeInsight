#include <iostream>
using namespace std;

int main() {
	int num[26] = {0};
	char input, res;

	while (cin>>input)
	{

		if (input >= 65 && input <= 90)
			num[input - 65]++;
		else if (input >= 97 && input <= 122)
			num[input - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		res = 'a' + i;
		cout << res << " : " << num[i] << endl;
	}

}