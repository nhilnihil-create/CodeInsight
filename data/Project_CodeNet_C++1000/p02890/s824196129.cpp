#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
const int MAXN=300100;
int a[MAXN];
int num[MAXN],use[MAXN],p[MAXN];
int po[MAXN],mo[MAXN];
long long ans[MAXN];
int tot;
int deal(int i,int x)
{
	int q=upper_bound(num+1,num+tot+1,x)-num;
	if(po[q-1]+(tot-q+1)*1LL*x>=1LL*x*i)  return 1;
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!use[a[i]])
		{
			p[++tot]=a[i];
			use[a[i]]=tot;
		}
		num[use[a[i]]]++;
	}
	sort(num+1,num+tot+1);
	for(int i=1;i<=tot;i++)  po[i]=po[i-1]+num[i];
	int now=0;
	for(int i=tot;i>=1;i--)
	{
		while(now<n && deal(i,now+1))  now++;
		ans[i]=now;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}