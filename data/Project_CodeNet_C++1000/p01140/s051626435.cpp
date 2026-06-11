#include<iostream>
#include<algorithm>
using namespace std;
int hc[1125750],wc[1125750];
main()
{
	int n,m;
	while(cin>>n>>m,n){
	int h[1501]={},w[1501]={};
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)h[i]+=h[i-1];
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)w[i]+=w[i-1];
	int c=0;
	for(int i=0;i<=n;i++)for(int j=i+1;j<=n;j++)hc[c++]=h[j]-h[i];
	int d=0;
	for(int i=0;i<=m;i++)for(int j=i+1;j<=m;j++)wc[d++]=w[j]-w[i];
	int cnt=0;
	sort(hc,hc+c);sort(wc,wc+d);
	for(int i=0;i<c;i++)
	{
		cnt+=upper_bound(wc,wc+d,hc[i])-lower_bound(wc,wc+d,hc[i]);
	}
	cout<<cnt<<endl;}
}