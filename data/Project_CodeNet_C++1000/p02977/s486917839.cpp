#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define ff first
#define ss second

int n,m;

inline int read(){
    int x=0,f=1; char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

int main(){
	n=read(); int x=__builtin_popcount(n);
	if (x==1){puts("No"); return 0;} puts("Yes");
	if (n==3){for (int i=1;i<(n*2);i++) printf("%d %d\n",i,i+1); return 0;}
	int pps=1; while ((pps<<1)<=n) pps<<=1;
	for (int i=1;i<pps-1;i++) printf("%d %d\n%d %d\n",i,i+1,i+n,i+1+n); printf("%d %d\n",pps-1,n+1);
	for (int i=pps;i<n;i+=2) printf("%d %d\n%d %d\n%d %d\n%d %d\n",i+1,i,i,1,1,i+n+1,i+n+1,i+n);
	if (!(n&1)) printf("%d %d\n%d %d\n",n,n+n-1,n+n,((n&-n)<<1)-2);
    return 0;
}
