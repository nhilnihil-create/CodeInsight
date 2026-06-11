#include<iostream>
using namespace std;
int m,d,k,sum;
int main()
{
	cin>>m>>d;
	for(int i=1;i<=m;++i)
	{
		for(int j=2;j*j<=i&&j<=9;++j)
		{
			k=i/j;
			if(k*j==i&&k>=2&&k<=9)
			{
				if(j*10+k<=d) sum++;
				if(k*10+j<=d) sum++;
				if(j*10+k<=d&&j==k) sum--;
			}
		}
	}
	cout<<sum;
}