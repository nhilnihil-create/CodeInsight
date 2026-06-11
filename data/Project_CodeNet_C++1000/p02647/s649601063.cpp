//love yjl forever
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int INF=0x3f3f3f3f,N=2e5+5;
int n,k;
int a[N],b[N];
void op()
{
	int i;
	for(i=1;i<=n;i++)
		b[i]=0;
	for(i=1;i<=n;i++)
	{
		int l=max(1,i-a[i]);
		int r=min(n,i+a[i]);
		b[l]++;
		b[r+1]--;
	}
	for(i=1;i<=n;i++) b[i]+=b[i-1];
	for(i=1;i<=n;i++)
		a[i]=b[i];
}
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=n) return 0;
	return 1;
}
int main()
{
/*	freopen("","r",stdin);
	freopen("","w",stdout);*/
	int i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=k;i++)
	{
		op();
		if(check()) break;
	}
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	
}