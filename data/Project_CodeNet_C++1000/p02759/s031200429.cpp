#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101][101] = {0};

int main()
{
	int a;
	cin >> a;
	if(a%2 == 0)
	{
		cout << a/2;	
	}	
	else
	{
		cout << a/2+1;
	}
}

