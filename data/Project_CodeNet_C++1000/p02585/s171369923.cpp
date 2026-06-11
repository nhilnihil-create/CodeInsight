#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include<bitset>
#include<cstdlib>
#include<set>
#include<unordered_map>
#define l(x) (x<<1)
#define r(x) ((x<<1)|1)
#define low(x) (x&(-x))
#define IL inline
#define reg register
#define LL long long
#define N 10010
#define MOD 998244353
#define MO 1000000007
#define INF 0x3f3f3f3f
using namespace std;

LL T,n,m,i,j,k,g,x,y,z,Ans,cnt,sum,res,Sum;
LL a[N],b[N],c[N],d[N*4],s[N];
bool v[N];

vector <LL> l[N];

IL LL Abs(LL x){return (x<0)?-x:x;}
IL void Swap(LL &a,LL &b){a^=b^=a^=b;}
IL LL Min(LL a,LL b){return (a<b)?a:b;}
IL LL Max(LL a,LL b){return (a>b)?a:b;}

IL LL Mi(LL x,LL y){
	LL p=x,t=1,Res=1;
	for (;t<=y;(t&y)?Res=(Res*p)%MOD:0,p=(p*p)%MOD,t<<=1);
	return Res;
}

IL LL read(){
	LL p=0,f=1;	char	c=getchar();
	while (c<48||c>57)	{if (c=='-')	f=-1;	c=getchar();}
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p*f;
}

IL void Dfs(int x){
	if (v[x])	return;
	c[cnt]+=b[x];	v[x]=1;
	l[cnt].push_back(b[x]);	Dfs(a[x]);
}

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	n=read();	k=read();
	for (i=1;i<=n;i++)	a[i]=read();
	for (i=1;i<=n;i++)	b[i]=read();
	for (i=1;i<=n;i++){
		if (!v[i])	++cnt,Dfs(i);
	}
/*	cout<<cnt<<endl;
	for (i=1;i<=cnt;i++)	cout<<c[i]<<endl;
	cout<<"---------"<<endl;
*/
	Ans=-INF;	sum=0;
	for (i=1;i<=cnt;i++){
		sum=0;
		for (j=0;j<l[i].size();j++)
			d[j+1]=d[j+1+l[i].size()]=l[i][j];
		s[0]=0;
		for (j=1;j<=l[i].size()*2;j++)	s[j]=s[j-1]+d[j];
		
		if (c[i]>0){
			sum=k/(l[i].size())*c[i];
			res=k%l[i].size();
			Sum=-INF;
			for (j=1;j<=l[i].size();j++)
				for (g=j;g<j+l[i].size();g++){
					if (g-j+1>res)	break;
					Sum=Max(Sum,s[g]-s[j-1]);
				}
			if (Sum!=-INF)	sum+=Sum;
			Ans=Max(Ans,sum);
			//total

			if (k>=l[i].size()){
				sum=((k-l[i].size())/l[i].size())*c[i];
				Sum=-INF;
				res=l[i].size();
				for (j=1;j<=l[i].size();j++)
					for (g=j;g<j+l[i].size();g++){
						if (g-j+1>res)	break;
						Sum=Max(Sum,s[g]-s[j-1]);
					}
				if (Sum!=-INF)	sum+=Sum;
				Ans=Max(Ans,sum);
			}
		}	else {
			res=l[i].size();
			Sum=-INF;
			for (j=1;j<=l[i].size();j++)
				for (g=j;g<j+l[i].size();g++){
					if (g-j+1>res)	break;
					Sum=Max(Sum,s[g]-s[j-1]);
				}
			Ans=Max(Ans,Sum);
		}
		//cout<<Ans<<endl;
	}
	cout<<Ans<<endl;
	return 0;
}