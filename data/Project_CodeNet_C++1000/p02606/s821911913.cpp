#include<iostream>
#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int main()
{
	ll l,r,d;
	cin >> l >> r >> d;
	if(l%d==0)
	{
		cout << (r-l)/d + 1 << endl;
	}
	else
	{
		if((l/d+1)*d<r)
		{
			if(r%d==0)
			{
				cout << (r-l)/d + 1 << endl;
			}
			else
			{
				cout << (r-l)/d << endl;
			}
		}
		else
		{
			cout << 0 << endl;
		}
	}
}