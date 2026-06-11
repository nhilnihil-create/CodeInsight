#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	int a, b, k, l;
	cin >> a >> b;
	for(int i=0; i<b; i++)
	{
		cin >> arr[i];
	}
	for(int i=a; i>=0; i--)
	{
		int t=0;
		for(int j=0; j<b; j++)
		{
			if(arr[j] != i)
			{
				t++;
			}	
		}
		if(t == b)
		{
			k=i;
			break;
		}	
	}
	for(int i=a; i<=101; i++)
	{
		int t=0;
		for(int j=0; j<b; j++)
		{
			if(arr[j] != i)
			{
				t++;
			}	
		}
		if(t == b)
		{
			l=i;
			break;
		}	
	}
	if(l-a > a-k)
	{
		cout << k;	
	}	
	else if(l-a < a-k)
	{
		cout << l;
	}
	else
	{
		cout << k;
	}
}

