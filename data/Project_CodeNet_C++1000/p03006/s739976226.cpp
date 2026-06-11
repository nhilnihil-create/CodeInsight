#include<bits/stdc++.h>
#define SIZE 55
 
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
 
ll X[SIZE],Y[SIZE];
 
int main()
{
	int n;
	scanf("%d",&n);
	set <P> st;
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld",&X[i],&Y[i]);
		st.insert(P(X[i],Y[i]));
	}
	vector <P> vx;
	int ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			P p=P(X[i]-X[j],Y[i]-Y[j]);
			int cnt=0;
			for(int k=0;k<n;k++)
			{
				P q=P(p.first+X[k],p.second+Y[k]);
				if(st.count(q)) cnt++;
			}
			ret=max(ret,cnt);
		}
	}
	printf("%d\n",n-ret);
	return 0;
}