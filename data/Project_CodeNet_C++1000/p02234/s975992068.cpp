#include<iostream>
using namespace std;
int min(int a,int b){return a<b?a:b;}
int p[101],m[101][101];
int main()
{	int n;
	cin>>n;
	for(int i=1;i<=n;i++)//总共有n+1个有效数据
		cin>>p[i-1]>>p[i];//保证只有n个有效的数据重复的不管
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int l=2;l<=n;l++)//这个l状态积累量
	{
		for(int i=1;i<=n-l+1;i++)
		{	int j=i+l-1;
			m[i][j]=(1<<21);//极大取极小,这个地方要有括号
			for(int k=i;k<=j-1;k++)//从i开始,对l开始累加
			{
				m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
			}

		}
	}
	cout<<m[1][n]<<endl;
	return 0;
}
