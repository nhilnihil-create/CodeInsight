#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k; //n：人数 k: 多少种类零食
	cin>>n>>k; //3 2
	int a[n+1];
	for(int i=1;i<=n;i++)	a[i]=0;
	
	int renshu,x;
	for(int i=1;i<=k;i++)
	{
		cin>>renshu;
		for(int j=1;j<=renshu;j++)
		{
			cin>>x;
			a[x]=1;
		}
	 } 
	 
	 int num=0;
	 for(int i=1;i<=n;i++)
	 {
	 	if(a[i]==0)
	 		num++;
	 }
	 
	 cout<<num<<endl;
	 
	 return 0;
}