#include<iostream>
#include<algorithm>
using namespace std;
int N;
long A[1<<17];
int B[1<<17][60];
main()
{
	cin>>N;
	long X=0;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		X^=A[i];
	}
	long Y=((1LL<<60)-1)^X;
	for(int i=0;i<N;i++)A[i]&=Y;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<60;j++)
		{
			B[i][j]=(A[i]>>59-j)&1;
		}
	}
	int id=0;
	for(int i=0;i<60;i++)
	{
		int t=id;
		while(t<N&&B[t][i]==0)t++;
		if(t==N)continue;
		if(t>id)
		{
			for(int j=0;j<60;j++)swap(B[id][j],B[t][j]);
		}
		for(int j=0;j<N;j++)
		{
			if(j==id||B[j][i]==0)continue;
			for(int k=0;k<60;k++)B[j][k]^=B[id][k];
		}
		id++;
	}
	long ans=0;
	for(int i=0;i<60;i++)
	{
		long t=0;
		for(int j=0;j<N;j++)t^=B[j][i];
		ans+=t<<59-i;
	}
	cout<<ans+(X^ans)<<endl;
}
