#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	int a, b;
	cin >> a >> b;
	for(int i=0; i<b; i++)
	{
		int c;
		cin >> c;
		a -= c;
	}
	if(a>=0)
	{
		cout << a;
	}
	else
	{
		cout << -1;
	}
}

