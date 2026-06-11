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
	if(a>b)
	{
		cout << "safe";
	}
	else
	{
		cout << "unsafe";
	}
}

