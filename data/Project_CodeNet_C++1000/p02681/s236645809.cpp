#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	string a, b;
	cin >> a >> b;
	int l=0;
	for(int i=0; i<a.length(); i++)
	{
		if(a[i] == b[i])
		{
			l++;
		}
	}
	if(l == a.length())
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}

