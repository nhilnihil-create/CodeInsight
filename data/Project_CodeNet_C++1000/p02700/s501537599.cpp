#include <bits/stdc++.h> 
using namespace std;

int main()
{
	long long gx,gg,qx,qg,max;
	cin >> gx >> gg >> qx >> qg;
	
	if (gx>qx)
		max=gx;
	else
		max=qx;
	
	for (long long i=1; i<=max+2; i++)
	{
		qx-=gg;
		if (qx<=0)
		{
			cout << "Yes" << endl;
			return 0;
		}
		
		gx-=qg;
		
		if (gx<=0)
		{
			cout << "No" << endl;
			return 0;
		}
	}
}