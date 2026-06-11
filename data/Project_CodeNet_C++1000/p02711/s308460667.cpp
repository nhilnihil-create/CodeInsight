#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	int a;
	cin >> a;
	while(a>0)
	{
		if(a%10 == 7)
		{
			cout << "Yes";
			return 0;
		}
		a/=10;
	}
	cout << "No";
}

