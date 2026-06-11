#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	long long x,id;
}s[7000004];
int cmp(node a,node b)
{
	if(a.x==b.x)return a.id<b.id;
	return a.x<b.x;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i].x,s[i].x-=1,s[i].id=i;
	for(int i=1;i<=n;i++)s[i].x=s[i-1].x+s[i].x,s[i].x%=m;
//	for(int i=0;i<=n;i++)cout<<s[i].x<<" ";cout<<endl;
	sort(s+1,s+1+n,cmp);//for(int i=0;i<=n;i++)cout<<s[i].x<<" ";cout<<endl;
	long long last=0,ans=0,cnt=0;
//	for(int i=1;i<=n;i++)if(s[i].x==1)ans++;
	int l=0,r=1;
	while(r<=n)
	{
	//	cout<<l<<" "<<r<<" ";
	//	cout<<s[l].id<<" "<<s[r].id<<" ";
		if(s[l].x!=s[r].x)
		{
			l=r;
			r++;
		}
		else 
		{
			while(s[r].id-s[l].id>=m&&l<r)
			{
				l++;
			}
			if(s[r].id-s[l].id<m)ans+=r-l,r++;
			else
			{
				l=r;r++;	
			}
		}
	//	cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}