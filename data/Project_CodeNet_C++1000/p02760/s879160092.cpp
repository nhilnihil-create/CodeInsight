#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101][101] = {0};

int main()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin >> arr[i][j];
		}
	}
	int a;
	cin >> a;
	for(int n=0; n<a; n++)
	{
		int o;
		cin >> o;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				if(o == arr[i][j])
				{
					arr[i][j] = 0;
				}
			}
		}
	}
	if(arr[0][0]==0 && arr[0][1]==0 && arr[0][2]==0)
	{
		cout << "Yes";
	}
	else if(arr[1][0]==0 && arr[1][1]==0 && arr[1][2]==0)
	{
		cout << "Yes";
	}
	else if(arr[2][0]==0 && arr[2][1]==0 && arr[2][2]==0)
	{
		cout << "Yes";
	}
	else if(arr[0][0]==0 && arr[1][0]==0 && arr[2][0]==0)
	{
		cout << "Yes";
	}
	else if(arr[0][1]==0 && arr[1][1]==0 && arr[2][1]==0)
	{
		cout << "Yes";
	}
	else if(arr[0][2]==0 && arr[1][2]==0 && arr[2][2]==0)
	{
		cout << "Yes";
	}
	else if(arr[0][0]==0 && arr[1][1]==0 && arr[2][2]==0)
	{
		cout << "Yes";
	}
	else if(arr[0][2]==0 && arr[1][1]==0 && arr[2][0]==0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}

