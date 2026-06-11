#include<iostream>
#include<map>
#include<vector>
using namespace std;
long long r[300001]={0};
long long c[300001]={0};
map<pair<long long, long long>,long long>mp;
vector<long long>r1;
vector<long long>c1;
//using namespace std;
int main()
{
	long long h,w,m,cnt=0,row=0,col=0,i,s1,s2,a,b;
	cin>>h>>w>>m;
	pair<long long,long long>p;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		r[a]++;
		c[b]++;
		p=make_pair(a,b);
		mp[p]=1;
	}
	for(i=1;i<=h;i++)
	{
		row=max(row,r[i]);
	}
	for(i=1;i<=w;i++)
	{
		col=max(col,c[i]);
	}
	for(i=1;i<=h;i++)
	{
		if(row==r[i])
		{
			r1.push_back(i);
		}
	}
	for(i=1;i<=w;i++)
	{
		if(col==c[i])
		{
			c1.push_back(i);
		}
	}
	s1=r1.size();
	s2=c1.size();
	for(i=0;i<s1;i++)
	{
		for(int j=0;j<s2;j++)
		{
			if(mp[make_pair(r1[i],c1[j])]==0)
			{
				cnt=1;
				break;
			}
		}
	}
	if(cnt==1)
	{
		cout<<row+col<<endl;
	}
	else
	{
		cout<<col+row-1<<endl;
	}
	return 0;
}