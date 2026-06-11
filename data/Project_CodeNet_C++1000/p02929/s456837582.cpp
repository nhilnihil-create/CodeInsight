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

const int mod = 1e9+7;

string s;
int n,num;
int main()
{
	long long ans=1;
    int i,j,k;
    scanf("%d",&n);
    cin>>s;
    for(i=0;i<2*n;i++)
    {
    	if(!(((s[i]=='W')^num)&1))
	 		num++;
        else
		{ 
			ans=1ll*ans*num%mod;
			num--;
		}
	}
    if(num)
		cout<<"0\n";
	else
	{
		for(i=1;i<=n;i++)
			ans=1ll*ans*i%mod;
	    cout<<ans<<"\n";	
	}
}


