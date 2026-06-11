#include<bits/stdc++.h>
using namespace std;

long long ans;
int x,y,a,b,c;
int P[100010],Q[100010],R[100010];
int p[100010],q[100010],r[100010];
int l1,l2,l3,r1,r2;

int main()
{
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&P[i]);
	for(int i=1;i<=b;i++) scanf("%d",&Q[i]);
	for(int i=1;i<=c;i++) scanf("%d",&R[i]);
	sort(P+1,P+1+a);
	sort(Q+1,Q+1+b);
	sort(R+1,R+1+c);
	for(int i=1;i<=a;i++) p[i]=P[a-i+1];
	for(int i=1;i<=b;i++) q[i]=Q[b-i+1];
	for(int i=1;i<=c;i++) r[i]=R[c-i+1];
	l1=l2=l3=0;
	r1=x;
	r2=y;
	for(int i=1;i<=x+y;i++)
	{
		if(l3==c)
		{
			for(int j=l1+1;j<=r1;j++) ans+=p[j];
			for(int j=l2+1;j<=r2;j++) ans+=q[j];
			break;
		}
		if(l1==r1)
		{
			if(q[l2+1]>=r[l3+1])
			{
				l2++;
				ans+=q[l2];
			}
			else
			{
				l3++;
				ans+=r[l3];
				r2--;
			}
		}
		else if(l2==r2)
		{
			if(p[l1+1]>=r[l3+1])
			{
				l1++;
				ans+=p[l1];
			}
			else
			{
				l3++;
				ans+=r[l3];
				r1--;
			}
		}
		else
		{
			if(p[l1+1]>=r[l3+1]&&p[l1+1]>=q[l2+1])
			{
				l1++;
				ans+=p[l1];
			}
			else if(q[l2+1]>=r[l3+1])
			{
				l2++;
				ans+=q[l2];
			}
			else
			{
				l3++;
				ans+=r[l3];
				if(p[r1]<q[r2]) r1--;
				else r2--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}