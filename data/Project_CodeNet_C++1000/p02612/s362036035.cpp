#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,r;
	cin>>n;
	r=n%1000;
	if(r==0)
	printf("0\n");
	if(r!=0)
	{
		printf("%d\n",1000-r);
	}
	
	
	return 0;
}