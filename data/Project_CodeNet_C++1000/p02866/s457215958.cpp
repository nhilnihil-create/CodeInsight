//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include <climits>
#include <cmath>
#include <cstring>

#include <iomanip>

using namespace std;

#define FAST       			ios_base :: sync_with_stdio(false); cin.tie(NULL); 
#define endl "\n"

typedef long long int  ll;
typedef unsigned long long int ull;

#define MOD 998244353

ll power(ll a , ll p)
{
	ll result = 1;
	while(p > 0)
	{
		// checking if last bit is 1 or not 
		if(p & 1)
			result = ( (result%MOD) * (a%MOD) ) % MOD;
		
		a = ( (a%MOD) * (a%MOD) ) % MOD;
		p = p>>1;
	}

	return result;
}

int main()
{
	FAST;
	int n;
	cin >> n;
	
	ll arr[n];
	
	for(int i=0 ; i<n ; i++)
		cin >> arr[i];
		
	if(arr[0] != 0)
	{
	    cout << "0";
	    return 0;
	}

	ll count[n];
	memset(count , 0 , sizeof(count));
	
	for(int i=0 ; i<n ; i++)
		count[arr[i]]++;
		
		
	if(count[0] != 1)
	{
	    cout << "0\n";
		return 0;
	}

	ll tree = 1;
	ll temp = n-1;
	for(int i=1 ; i<n ; i++)
	{
		if(count[i] == 0)
		{
		    if(temp == 0)
				break;
			cout << "0\n";
			return 0;
		}

		temp -= count[i];
		tree = (tree * power(count[i-1] , count[i]))%MOD;
	}

	cout << tree << "\n";
	return 0;
}