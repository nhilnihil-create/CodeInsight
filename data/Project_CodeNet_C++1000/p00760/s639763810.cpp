#include<iostream>
using namespace std;
int d[2][10]={
	{20,19,20,19,20,19,20,19,20,19},
	{20,20,20,20,20,20,20,20,20,20}
};
int m[1000];
main()
{
	int n;
	cin>>n;
	for(int i=1000;--i;)
	{
		m[i]=m[i+1];
		for(int j=0;j<10;j++)m[i]+=d[i%3<1][j];
	}
	for(;n--;)
	{
		int Y,M,D;cin>>Y>>M>>D;
		int cnt=d[Y%3<1][M-1]-D+1;
		for(int i=M;i<10;i++)cnt+=d[Y%3<1][i];
		cout<<m[Y+1]+cnt<<endl;
	}
}

