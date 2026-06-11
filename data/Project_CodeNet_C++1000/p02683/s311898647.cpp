#include"iostream"

using namespace std;

int main()
{
	int n,m,x,i,j,a[15][15],s[15]={0},min,k;
	cin>>n>>m>>x;
	min=-1;
	for(i=0;i<n;i++)
		for(j=0;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<(1<<n);i++)
	{
		for(k=0;k<=m;k++)
			s[k]=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{	
				for(k=0;k<=m;k++)
					s[k]+=a[j][k];
			}
		}
		for(k=1;k<=m;k++)
			if(s[k]<x) break;
		if(k>m&&((min==-1)||s[0]<min)) min=s[0];
	}
	cout<<min<<endl;
	return 0;
}
