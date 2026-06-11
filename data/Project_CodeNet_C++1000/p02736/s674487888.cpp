#include <bits/stdc++.h>
#define SIZE 1000005
using namespace std;

int A[SIZE];
char str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	bool up=true;
	for(int i=0;i<n;i++)
	{
		A[i]=str[i]-'0';
		A[i]--;
		if(A[i]==1) up=false;
	}
	if(up)
	{
		for(int i=0;i<n;i++) A[i]/=2;
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{
		if(((n-1)&i)==i)
		{
			ret^=A[i]%2;
		}
	}
	if(up) ret*=2;
	printf("%d\n",ret);
	return 0;
}