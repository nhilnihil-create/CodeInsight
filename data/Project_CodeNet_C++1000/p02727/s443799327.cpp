#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010];
ll b[100010];
ll c[100010];
ll ans=0;
bool cmp(ll a,ll b){return a>b;}
int main()
{
    int x,y,A,B,C;
    cin>>x>>y>>A>>B>>C;
	for(int i=1;i<=A;i++)  scanf("%lld",&a[i]);
	sort(a+1,a+1+A,cmp);
    for(int i=1;i<=B;i++)  scanf("%lld",&b[i]);
    sort(b+1,b+1+B,cmp);
    for(int i=1;i<=C;i++)  scanf("%lld",&c[i]);
    sort(c+1,c+1+C,cmp);
    
    int p1,p2,p3;
    p1=p2=p3=1;
    
	while(p1+p2+p3-3<x+y)
    {
    	if(p1<=x && a[p1]>=b[p2] && a[p1]>=c[p3])
    	{
    		ans+=a[p1];
    		p1++;
    		if(p1>x)   a[p1]=0;
		}
		else if(p2<=y && b[p2]>=c[p3] && b[p2]>=a[p1])
    	{
    		ans+=b[p2];
    		p2++;
    		if(p2>y)   b[p2]=0;
		}
		else if(p3<=C && c[p3]>=b[p2] && c[p3]>=a[p1])
    	{
    		ans+=c[p3];
    		p3++;
		}
		
	//	cout<<p1<<" "<<p2<<" "<<p3<<endl;
	}
	cout<<ans<<endl;
    return 0;
}