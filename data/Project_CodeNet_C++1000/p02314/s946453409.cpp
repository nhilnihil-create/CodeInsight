#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=50000+10,maxm=20+10;
int n,m;
int d[maxm],f[maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>d[i];
	memset(f,0x3f,sizeof(f));
	f[0]=0,f[1]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=n;j++)
			if(j-d[i]>=0)
				f[j]=min(f[j],f[j-d[i]]+1);
	cout<<f[n]<<endl;
	return 0;
}