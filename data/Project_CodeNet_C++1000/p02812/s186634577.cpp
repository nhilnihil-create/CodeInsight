#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
	int n,i,j,c,c1=0;
	cin>>n;
	string s1="ABC";
	string s2;
	cin>>s2;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
			{
				if(s1[j]!=s2[i+j])
					break;
			}
		if(j==3)
		{
			c1++;
			j=0;
		}
	}
		
	cout<<c1<<endl;	
}