#include <iostream>
#include <string>

#define rep(i,n)      for(int i=0;i<n;i++)

using namespace std;

string s;
int p;

bool check()
{
	bool ret = true;
	while (s[p] != '.' && s[p] != ')' && s[p] != ']')
	{
		char c = s[p++];
		if (c == '(' || c == '[')
		{
			char end = c == '(' ? ')' : ']';
			ret = check();
			if (s[p] == end) p++;
			else ret = false;
		}
		if (!ret) break;
	}
	return ret;
}

bool checkall()
{
	p = 0;
	bool ret = check();
	ret = ret && s[p] == '.';
	return ret;
}

int main()
{
	while(getline(cin, s), s[0] != '.')
	{
		cout << (checkall() ? "yes" : "no") << endl;
	}
}