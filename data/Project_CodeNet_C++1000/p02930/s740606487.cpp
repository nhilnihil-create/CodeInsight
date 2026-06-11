#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<time.h>
#include<sstream>
#define MINN -1e8 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF=0x3f3f3f3f3f3f;
const int P=1e9+7;
const int MAXN=32000;
const double pi=3.1415926;
const ll mod=1000000007;
int a[505][505],n;
void f(int l,int r,int tmp)
{
	if(l==r)return;
	int mid=(r+l)/2;
	for(int i=l;i<=mid;i++)
	{
		for(int j=mid+1;j<=r;j++)
		{
			a[i][j]=tmp;
		}
	}
	if(r!=l+1)
	{
		f(l,mid,tmp+1);
		f(mid+1,r,tmp+1);
	}
}
int main()
{
	cin>>n;
	f(1,n,1);
	for(int i=1;i<=n-1;i++)
	{
		cout<<a[i][i+1];
		for(int j=i+2;j<=n;j++)
		{
			cout<<" "<<a[i][j];
		}
		cout<<'\n';
	}
	return 0;
}