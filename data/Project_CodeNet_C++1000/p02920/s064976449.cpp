#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int MN=20;
const int M=(1<<18)+5;

int cnt[M];

int n,m;

struct SegT
{
	int sum[M*2];
	void pull(int o,int ls,int rs)
	{
		sum[o]=sum[ls]+sum[rs];
	}
	void build(int o,int l,int r)
	{
		if(l==r)
		{
			sum[o]=cnt[l];
			return;
		}
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		build(ls,l,mid);
		build(rs,mid+1,r);
		pull(o,ls,rs);
	}
	int R;
	int query(int o,int l,int r)
	{
		if(r<=R) return sum[o];
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		int ans=query(ls,l,mid);
		if(mid<R)
			ans+=query(rs,mid+1,r);
		return ans;
	}
	int sub(int o,int l,int r,int kth)
	{
		if(l==r)
		{
			sum[o]--;
			return l;
		}
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		int ans=-1;
		if(sum[ls]>=kth)
			ans=sub(ls,l,mid,kth);
		else
			ans=sub(rs,mid+1,r,kth-sum[ls]);
		pull(o,ls,rs);
		return ans;
	}
}segt;

int mx;
vector<int> vec;
bool solve()
{
	vec.push_back(m-1);
	segt.build(0,0,m-1);
	for(int i=0;i<n;i++)
	{
		int l=1<<i;
		//cout<<l<<endl;
		for(int j=0;j<l;j++)
		{
			int u=vec[j];
			segt.R=u-1;
			int sum=segt.query(0,0,m-1);
			//cout<<sum<<endl;
			if(!sum) return false;
			int v=segt.sub(0,0,m-1,sum);
			vec.push_back(v);
		}
	}
	return true;
}

map<int,int> ma;

int main()
{
	scanf("%d",&n);
	m=1<<n;
	int s,mx=-1;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&s);
		mx=max(mx,s);
		ma[s]++;
	}
	ma[mx]--;
	m=1;
	for(auto p:ma)
		cnt[m++]=p.second;
	printf("%s\n",solve()?"Yes":"No");
}