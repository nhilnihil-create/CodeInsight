#include<string>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int temp=0,total=0;
	string a;
	cin>>a;
	a.push_back('S');
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='R')
		{ 
			total++;
		}
		else
		{
			temp=max(temp,total);
			total=0;
			}
	}
	cout<<temp;
}
