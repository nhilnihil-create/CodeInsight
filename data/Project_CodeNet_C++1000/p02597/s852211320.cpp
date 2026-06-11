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
#define N 500010
#define MOD 998244353
#define MO 1000000007
#define INF 0x3f3f3f3f
using namespace std;

int T,n,i,j,k,x,y,z,l,r;
int a[N],b[N];
char c[N];

struct Data{
	int x,y;
}d[N];

IL int Abs(int x){return (x<0)?-x:x;}
IL void Swap(int &a,int &b){a^=b^=a^=b;}
IL int Min(int a,int b){return (a<b)?a:b;}
IL int Max(int a,int b){return (a>b)?a:b;}
IL bool cmp(const Data a,const Data b){return a.x<b.x;}

IL LL Mi(LL x,LL y){
	LL p=x,t=1,Res=1;
	for (;t<=y;(t&y)?Res=(Res*p)%MOD:0,p=(p*p)%MOD,t<<=1);
	return Res;
}

IL int read(){
	int p=0,f=1;	char	c=getchar();
	while (c<48||c>57)	{if (c=='-')	f=-1;	c=getchar();}
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p*f;
}

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	n=read();
	scanf("%s",c+1);
	for (i=1;i<=n;i++){
		if (c[i]=='W'){
			l=i;	break;
		}
	}
	for (i=n;i;i--){
		if (c[i]=='R'){
			r=i;	break;
		}
	}
	if (!l || !r)	{
		cout<<"0"<<endl;
		return 0;
	}
	int Ans=0;
	while (l<r){
		Ans++;
		l++;	r--;
		while (l<=n && c[l]=='R')	l++;
		while (r && c[r]=='W')	r--;
		if (l>n || r<0)	break;
		if (l>r)	break;
	}
	cout<<Ans<<endl;
	return 0;
}