#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int arr[101] = {0};

int main()
{
	int a, total2=9999999;
	cin >> a;
	for(int i=0; i<a; i++)
	{
		cin >> arr[i];
	}
	for(int i=0; i<=100; i++)
	{
		int total=0;
		for(int j=0; j<a; j++)
		{
			total += (arr[j]-i)*(arr[j]-i);
		}
		if(total < total2)
		{
			total2=total;	
		}
	}
	cout << total2;
}

