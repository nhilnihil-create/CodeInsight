/*
ID: lalitkumar__
TASK: A
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
//	freopen("beads.in","r",stdin);
//	freopen("beads.out","w",stdout);

int x,y;
cin>>x>>y;
if(x==1 && y==1)
{  int xx = 300000+300000+400000;
	cout<<xx<<endl;
	return 0;
}
int ans = 0;
if(x==1)
{
	ans+=300000;
}
if(x==2)
{
	ans+=200000;
}
if(x==3)
{
	ans+=100000;
}
if(y==1)
{
	ans+=300000;
}
if(y==2)
{
	ans+=200000;
}
if(y==3)
{
	ans+=100000;
}
cout<<ans<<endl;


}