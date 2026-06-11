#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
	int a,i,b;
	cin>>a>>b;
	for(i=0;i<=20;i++)
		if(a*i-i+1>=b)
			{
				cout<<i<<endl;
				break;
			}
}