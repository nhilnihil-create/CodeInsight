#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int a[27];
int s, t;
int main()
{
	s=0;
	t=0;
	for(int i=0; i<28; i++)
	{
		cin >> a[i];
	}
	for(int i=1; i<=30; i++)
	{
		int j=0;
		for(int k=0; k<28; k++)
		{
			if(a[k]==i){j+=1;}
			else{}
		}
		if(j==0)
		{
			if(s!=0)
			{
				t=i;	
			}
			else
			{
				s=i;
			}
		}
		else{}
	}
	cout << s << endl << t << endl;
	return 0;
}