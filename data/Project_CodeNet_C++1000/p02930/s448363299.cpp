#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
int n,a[510][510];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

void solve(int l,int r,int id)
{
	if (l==r) return;
	int mid=(l+r)>>1;
	rep(i,l,mid) rep(j,mid+1,r) a[i][j]=id;
	solve(l,mid,id+1);solve(mid+1,r,id+1);
}

int main()
{
	n=read();
	solve(1,n,1);
	rep(i,1,n) 
	{
		rep(j,i+1,n) printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}