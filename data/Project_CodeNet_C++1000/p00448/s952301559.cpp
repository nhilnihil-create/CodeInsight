#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;
bitset<10000>a[10];
int main()
{
	int H,W,count,sum;
	while(cin>>H>>W,H)
	{
		int temp;
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				cin>>temp;
				if(temp)a[i].set(j);
				else a[i].reset(j);
			}
		}
		sum=0;
		for(int cur=0;cur<(1<<H);cur++)
		{
			count=0;
			for(int i=0;i<H;i++)
			{
				if((cur>>i)&1)a[i].flip();
			}
			for(int j=0;j<W;j++)
			{
				temp=0;
				for(int i=0;i<H;i++)
				{
					if(a[i].test(j))temp++;
				}
				count+=max(temp,H-temp);
			}
			sum=max(count,sum);
			for(int i=0;i<H;i++)
			{
				if((cur>>i)&1)a[i].flip();
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}