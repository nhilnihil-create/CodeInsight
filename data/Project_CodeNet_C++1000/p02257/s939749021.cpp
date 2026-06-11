#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>
#include<iomanip>
#include<queue>
#include<set>
#include <valarray>
#include<stack>
#include<sstream>
#include<math.h>

#define REP(i, a, b) for(i = a; i<b; i++)
#define rep(i, n) REP(i, 0, n)

using namespace std;

bool Solution(int data)
{
	int i;

	if (data < 2) 
	{
		return false;
	}
	else if (data == 2) 
	{
		return true;
	}

	if(data % 2 == 0) 
	{
		return false;
	}

	for (i = 3; i * i <= data; i += 2) 
	{
		if (data % i == 0) 
		{
			return false;
		}
	}

	return true;

}

int main()
{
	int n, m, i; 
	int count = 0;
	
	cin >> n;
	
	rep(i, n) 
	{
		cin >> m;
		if (Solution(m)) 
		{
			count++;
		}
	}
	cout << count << endl;
}