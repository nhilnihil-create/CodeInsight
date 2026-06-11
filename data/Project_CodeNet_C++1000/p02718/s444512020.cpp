#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	long long int a, b, total=0, n=0;
	cin >> a >> b;
	for(int i=0; i<a; i++)
	{
		int c;
		cin >> arr[i];
	}
	for(int i=0; i<a; i++)
	{
		total += arr[i];
	}
	for(int i=0; i<a; i++)
	{
		if(arr[i]*4*b >= total)
		{
			n ++;
		}
	}
	if(n >= b)
	{
		cout << "Yes";
	}
	else 
	{
		cout << "No";
	}
}

