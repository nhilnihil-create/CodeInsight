#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char ch;
int mp[10][10];
int ans=0;
int sum=0;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	  {
	  	cin>>ch;
	  	if(ch=='#')  {mp[i][j]=1;sum++;}   
	  }
	
	for(int i=0;i<(1<<n);i++)
	  for(int j=0;j<(1<<m);j++)
	  {
	  	int num=0;
		  for(int p=0;p<n;p++)
		   for(int q=0;q<m;q++)
		   {
		   	if(mp[p][q] && ((i&(1<<p)) || (j&(1<<q))))  num++;
		   }
		if(num==sum-k)  ans++; 
	  }
	cout<<ans<<endl;
	return 0;
}