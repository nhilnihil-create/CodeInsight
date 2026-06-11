#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
 
using namespace std;
 
typedef long long ll;
const int maxn=1e5+7;
const ll mod= 998244353;

struct node
{
	ll x,y;
}a[1110];

bool cmp(node a,node b)
{
	return atan2(a.y,a.x)<atan2(b.y,b.x);
}
 
int main()
{
//	freopen("input.txt","r",stdin);
	
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++) cin>>a[i].x>>a[i].y;
	sort(a,a+n,cmp);
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		ll x=a[i].x,y=a[i].y;
		ans=max(ans,x*x+y*y);
		for(ll j=(i+1)%n;j!=i;j=(j+1)%n)
		{
			x+=a[j].x,y+=a[j].y;
			ans=max(ans,x*x+y*y);
		}
	}
	double res=sqrt(ans);
	printf("%.13f\n",res);
    
    return 0;
}


// 结构体外面只能进行定义变量，不能进行赋值，也不能进行表达式的计算 












