#include <iostream>
using namespace std;

int main()
{
	int sum=0;
	string s, t;
	getline(cin, s);
	getline(cin, t);
	
	for(int i=0; i<s.size(); ++i)
	{
		if(s[i]!=t[i])
		{
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}