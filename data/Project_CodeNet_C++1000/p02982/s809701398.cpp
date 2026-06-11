#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,d,i,j,k,a[20][20],sum=0,count=0;
	cin >> n >> d;
		
	for(i=0;i<n;i++)
	{
		for(j=0;j<d;j++)
		{
			cin >> a[i][j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(k=i;k<n;k++)
		{
			for(j=0;j<d;j++)
			{
				sum+=pow(abs(a[i][j]-a[k][j]),2);
			}
			int inte = abs(sqrt(sum));
			if (sqrt(sum)==inte && sqrt(sum) != 0) count++ ;
		//	cout << sqrt(sum) << endl;
			sum=0;
		}
	}
	
	cout << count ;
}