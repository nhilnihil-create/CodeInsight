#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#define l(x) (x<<1)
#define r(x) ((x<<1)|1)
#define IL inline
#define reg register
#define LL long long
#define N 200010
#define INF 0x3f3f3f3f
using namespace std;

int n,i;
LL t;
LL p[4];
LL Ans;

struct Data{
	LL x,y;
}a[N];

IL int Abs(int x){return (x<0)?-x:x;}
IL void Swap(int &a,int &b){a^=b^=a^=b;}
IL int Min(int a,int b){return (a<b)?a:b;}
IL int Max(int a,int b){return (a>b)?a:b;}

IL int read(){
	int p=0,f=1;	char	c=getchar();
	while (c<48||c>57)	{if (c=='-')	f=-1;	c=getchar();}
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p*f;
}

IL void Insert(LL x,LL y){
	LL t=0;
	t=-(x+y);	p[0]=Max(p[0],t);
	t=-(x-y);	p[1]=Max(p[1],t);
	t=-(-x+y);	p[2]=Max(p[2],t);
	t=-(-x-y);	p[3]=Max(p[3],t);
}

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	n=read();
	for (i=1;i<=n;i++)	a[i].x=read(),a[i].y=read();
	p[0]=p[1]=p[2]=p[3]=-INF;
	Insert(a[1].x,a[1].y);
	Ans=-INF;
	for (i=2;i<=n;i++){
		t=(a[i].x+a[i].y);	Ans=Max(Ans,t+p[0]);
		t=(a[i].x-a[i].y);	Ans=Max(Ans,t+p[1]);
		t=(-a[i].x+a[i].y);	Ans=Max(Ans,t+p[2]);
		t=(-a[i].x-a[i].y);	Ans=Max(Ans,t+p[3]);
		Insert(a[i].x,a[i].y);
	}
	cout<<Ans<<endl;
	return 0;
}