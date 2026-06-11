#include<iostream>
using namespace std;
int main()
{
	char s[4];
	int flag=0;
	scanf("%s",&s);
	for(int i=1;i<4;i++)
	{
		if(s[i]==s[i-1])
		{
		flag=1;break;
		}
	}
	if(flag==1)
	cout<<"Bad";
	else
	cout<<"Good";
} 