#include<iostream>
using namespace std;
#include<string>
#include <set>
int main()
{
	int n;
	set <string, greater <string> > str1;
	string str;
	cin >> n;
	while(n--)
	{
		cin >> str;
		str1.insert(str);
	}
	cout<<str1.size()<<endl;
	return 0;
}
	
			
