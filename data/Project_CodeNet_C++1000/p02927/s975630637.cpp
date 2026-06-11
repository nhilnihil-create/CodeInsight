#include <iostream>
using namespace std;
int pd(int a,int b)
{
	if ((b%10)*(b/10)==a&&(b%10)>=2&&(b/10)>=2)  return true;
	else return false;
}
int main()
{
	int m,n,total=0;
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (pd(i,j)) total++;
		}
	}
	cout<<total<<endl;
	return 0;
}