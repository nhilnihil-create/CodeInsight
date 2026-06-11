#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int a;
	cin >> a;
	string b;
	cin >> b;
	for(int i=0; i<min(a, (int)b.length()); i++)
	{
		cout << b[i];
	}
	if(a<b.length())
	{
		cout << "...";
	}
}

