#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n=0;

	while(cin >> n && n)
	{
		int num[500000]={};
		int count=0;

		for(int i=n+1;i<=2*n;i++)num[i]=1;
		for(int i=2;i<=sqrt(2*n);i++)
		{
			for(int j=1;j*i<=2*n;j++)
				num[i*j]=0;
		}
		for(int i=n+1;i<=2*n;i++)if(num[i])count++;
		cout<< count << endl;
	}

    return 0;
}