#include<iostream>
#include<vector>

using namespace std;

int write(int x,int y)
{
	for(int k=0;k<x;k++)
	{
		for(int l=0;l<y;l++)
		{
			cout<<"#";
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
	
}

