


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include <functional>

using namespace std;

int INF = 10000000;

int n;



int cast(int n)
{
	int sum = 0;
	for(int i = 1;i < n;i++)
	{
		int temp = 0;
		for(int j = i;j < n;j++)
		{
			temp += j;
			if(temp == n)
				sum++;
		}
	}
	return sum;
}


int main()
{
	int n;
	while(cin >> n && n)
	{
		cout << cast(n) << endl;
	}

  return 0;
}