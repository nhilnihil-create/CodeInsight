#include<iostream>
#include<cmath>

using namespace std;

#define REP(i,n) for(int i = 0;i < n;i++)
	
int e,r,t;
int main()
{
	while(cin >> e,e)
	{
		int z;r = 1e9;
		for(int z = 0;z*z*z <= e;z++)
		{
			t = sqrt(e-z*z*z);
			r = min(r,e-z*z*z-t*t+t+z);
		}
		
		cout << r << endl;
		
	}
	
	return 0;
}