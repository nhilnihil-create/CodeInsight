#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int n,x,count;
	
	while(1)
	{
		count=0;
		
		cin >> n >> x;
		
		if(n==0&&x==0)break;
		
		for(int h=1;h<=n;h++)
		{
			for(int i=h+1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if((h+i+j)==x)
					{
						count++;
					}
				}
			}
		}
		
		cout << count << "\n";
		
	}
		
return 0;
}