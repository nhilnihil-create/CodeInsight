#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	int a, b=0;
	cin >> a;
	for(int i=0; i<a; i++)
	{
		cin >> arr[i];
	}
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<i; j++)
		{
			for(int k=0; k<j; k++)
			{
				int p=0;
				if(arr[i] != arr[j] && arr[i] != arr[k] && arr[j] != arr[k])
				{
					if(arr[i]+arr[j] > arr[k])
					{
						p++;
					}
					if(arr[i]+arr[k] > arr[j])
					{
						p++;
					}
					if(arr[j]+arr[k] > arr[i])
					{
						p++;
					}
				}
				if(p==3)
				{
					b += 1;
				}
			}
		}
	}
	cout << b;
}

