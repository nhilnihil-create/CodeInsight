#include<iostream>
using namespace std;
int m,d,k,sum;
int main()
{
	cin>>m>>d;
	for(int i=1;i<=m;i++)
	{
		for(int j=22;j<=d;j++)
		{
            int d1=j/10;
            int d10=j%10;
            if(d1*d10==i&&d10>=2&&d1>=2)
            {
                 sum++;
                 //cout<<sum<<' '<<i<<' '<<j<<endl;
            }
		}
	}
	cout<<sum<<endl;
}
