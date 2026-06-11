#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+9;
const double ep=1e-2;
const int mod=1e9+7;
const double pi=acos(-1);
const int INF=0x3f3f3f3f;
#define debug1 puts("?");
#define debug(x) cout<<"##"<<(x)<<endl;
#define mk make_pair
#define PII pair<int,int>
#define PIII pair<PII,int>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define eb emplace_back
#define fi first
#define se second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define sd(x) scanf("%d",&(x))
#define slld(x) scanf("%lld",&(x))
#define sdd(x,y) scanf("%d%d",&(x),&(y))
#define sc(s) scanf("%s",(s))
#define pd(x) printf("%d\n",(x))
#define plld(x) printf("%lld\n",(x))
#define pdk(x) printf("%d ",(x))
typedef long long ll;
map<PII,bool>mp;
int h,w,m,res,r[maxn],c[maxn];
int a[maxn],b[maxn];
bool cmp1(int a,int b)
{
	return r[a]>r[b];
}
bool cmp2(int a,int b)
{
	return c[a]>c[b];
}
void solve()
{
	scanf("%d%d%d",&h,&w,&m);
	rep(i,1,max(h,w))a[i]=b[i]=i;
	rep(i,1,m)
	{
		int u,v;
		sdd(u,v);
		mp[mk(u,v)]=1;
		r[u]++;c[v]++;
	}
	sort(a+1,a+1+h,cmp1);
	sort(b+1,b+1+w,cmp2);
	res=r[a[1]]+c[b[1]];
	if(mp[mk(a[1],b[1])])res--;
	else
	{
		pd(res);return;
	}
	r[a[0]]=r[a[1]];c[b[0]]=c[b[1]];
	bool ju=0;
	rep(i,1,h)
	{
		if(!r[a[i]])break;
		if(r[a[i]]!=r[a[i-1]])break;
		rep(j,1,w)
		{
			if(!c[b[j]])break;
			if(c[b[j]]!=c[b[j-1]])break;
			if(!mp[mk(a[i],b[j])])
			{
				res++;ju=1;break;
			}
		}	
		if(ju)break;
	}
	pd(res);
}
int main()
{
	int T=1;
//	sd(T);
	while(T--)solve();
}