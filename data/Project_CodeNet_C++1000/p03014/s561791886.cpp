#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int h,w;
	cin>>h>>w;
	string arr[h];
	for(int i=0;i<h;i++)
		cin>>arr[i];
	int prerow[h][w];
	int precol[h][w];
	int sufcol[h][w];
	int sufrow[h][w];
	for(int i=0;i<h;i++)
	{
		prerow[i][0]=-1;
		sufrow[i][w-1]=w;
		if(arr[i][0]=='#')
			prerow[i][0]=0;
		if(arr[i][w-1]=='#')
			sufrow[i][w-1]=w-1;

	}
	for(int i=0;i<w;i++)
	{
		precol[0][i]=-1;
		sufcol[h-1][i]=h;
		if(arr[0][i]=='#')
			precol[0][i]=0;
		if(arr[h-1][i]=='#')
			sufcol[h-1][i]=h-1;
	}
	
	for(int i=0;i<h;i++)
	{
		for(int j=1;j<w;j++)
		{
			if(arr[i][j]=='#')
				prerow[i][j]=j;
			else
				prerow[i][j]=prerow[i][j-1];
		}
	}
	for(int i=0;i<w;i++)
	{
		for(int j=1;j<h;j++)
		{
			if(arr[j][i]=='#')
				precol[j][i]=j;
			else
				precol[j][i]=precol[j-1][i];
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=w-2;j>=0;j--)
		{
			if(arr[i][j]=='#')
				sufrow[i][j]=j;
			else
				sufrow[i][j]=sufrow[i][j+1];
		}
	}
	for(int i=0;i<w;i++)
	{
		for(int j=h-2;j>=0;j--)
		{
			if(arr[j][i]=='#')
				sufcol[j][i]=j;
			else
				sufcol[j][i]=sufcol[j+1][i];
		}
	}
	ll fmax=0;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{	
			ll max=0;
			if(arr[i][j]!='#')
				max = (j- prerow[i][j])+(i-precol[i][j])+(sufrow[i][j]-j)+(sufcol[i][j]-i)-3;
			if(fmax<max)
				fmax=max;
		}
	}

	

	cout<<fmax<<"\n";

}