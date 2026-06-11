#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string arr[7] = {};

int main()
{
	int a, b, k, answer=0;
	cin >> a >> b >> k;
	for(int i=0; i<a; i++)
	{
		cin >> arr[i];
	}
	for(int i=0; i<(1<<a); i++)
	{
		for(int j=0; j<(1<<b); j++)
		{
			int p=i, l=j;
			int arr2[a]={0};
			int arr3[b]={0};
			for(int u=0; u<a; u++)
			{
				arr2[u] = p%2;
				p /= 2;
			}
			for(int u=0; u<b; u++)
			{
				arr3[u] = l%2;
				l/=2;
			}
			int t=0;
			for(int u=0; u<a; u++)
			{
				for(int y=0; y<b; y++)
				{
					if(arr[u][y]=='#' && arr2[u]==0 && arr3[y]==0)
					{
						t ++;
					}
				}
			}
			if(t==k)
			{
				answer++;
			}
		}
	}
	cout << answer;
}

