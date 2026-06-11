#include<bits/stdc++.h>
using namespace std;
int n,m,has,k;
char arr[10][10],sim[10][10];
void reset()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) arr[i][j]=sim[i][j];
	}
}
void f(int a,int b)
{
	int t;
	for(int i=0;i<6;i++)
	{
		t=1<<i;
		if(a&t)
		{
			for(int j=0;j<m;j++) arr[i][j]='*';
		}
	}
	for(int i=0;i<6;i++)
	{
		t=1<<i;
		if(b&t)
		{
			for(int j=0;j<n;j++) arr[j][i]='*';
		}
	}
	int now=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) if(arr[i][j]=='#') now++;
	}
	if(now==k) has++;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cin>>arr[i][j],sim[i][j]=arr[i][j];
	}
	for(int i=0;i<pow(2,n);i++)
	{
		for(int j=0;j<pow(2,m);j++)
		{
			f(i,j);
			reset();
		}
	}
	cout<<has<<endl;
}