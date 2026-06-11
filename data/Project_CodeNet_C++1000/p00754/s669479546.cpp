#include <iostream>
#include <string>

using namespace std;

bool check(string str_f)
{
	if (str_f.empty() == 1)return true;
	for (unsigned int i = 0; i<str_f.length() ; i++)
	{
		if ((str_f[i] == '(' && str_f[i + 1] == ')') || (str_f[i] == '[' && str_f[i + 1] == ']'))
		{
			str_f.erase(str_f.begin() + i);
			str_f.erase(str_f.begin() + i);
			return check(str_f);         
		}
	}
	return false;
}

int main()
{
	while (true)
	{
		string str = "";
		string str_f = "";
		getline(cin, str);
		if (str[0] == '.')break;
		for (unsigned int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(' ||
				str[i] == '[' ||
				str[i] == ')' ||
				str[i] == ']') str_f += str[i];
		}
		int a = str_f.length();
		if (a % 2 == 1)							
		{
			cout << "no" << endl;
			continue;
		}
		if (check(str_f))cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}