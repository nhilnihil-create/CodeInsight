#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <map>
#include <stack>
#include <cmath>
#define LL long long 
using namespace std;

int main()
{
	int m,d,ans=0;
	scanf("%d%d",&m,&d);
	for(int i=4;i<=m;i++)
	{
		for(int j=2;j<=(d/10);j++)
		{
			for(int k=2;k<=9;k++)
			{
				if((j*10+k)>d)
					break;
				if(j*k==i)
					ans++;
			}
		}
	}
	cout<<ans<<endl;
}

