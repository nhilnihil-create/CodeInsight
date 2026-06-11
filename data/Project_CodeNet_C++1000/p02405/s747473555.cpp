#include<iostream>
#include<vector>

using namespace std;

int write(int x,int y)
{
	int z=0;
	for(int j=0;j<x;j++)
	{
		for(int k=0;k<y;k++)
		{
			if(z==0)
			{
				cout<<"#";
				z=1;
			}
			else
			{
				cout<<".";
				z=0;
			}
		}
		if(y%2==0)
		{
			if(z==0)
				z=1;
			else
				z=0;
		}
		cout<<endl;
	}
	return(0);
}

int main()
{
	int a,b;
	unsigned int i=0;
	unsigned int j;
	vector<int> n;
	vector<int> m;
	
	while(1)
	{
		cin>>a>>b;
		
		if(a==0&&b==0)
			break;
		else
		{
		n.push_back(a);
		m.push_back(b);
		i++;
		}
	}
	for(j=0;j<i;j++)
	{
		write(n[j],m[j]);
		cout<<endl;
	}
	return(0);
}

