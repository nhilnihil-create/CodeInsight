#include<bits/stdc++.h>
using namespace std;
#define rg register
#define rep(i,a,b) for (rg int i=a;i<=b;i++)
#define per(i,a,b) for (rg int i=b;i>=a;i--)
#define pb push_back
#define lowbit(x) (x&(-x))
#define mk make_pair
#define VI vector<int>
#define pii pair<int,int>
#define pLL pair<long long,long long>
#define fi first
#define se second
#define il inline
#define ll long long
#define db double
#define ld long double
#define inf 0x3f3f3f3f
#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<15,stdin),p1==p2)?EOF:*p1++)
char buf[1<<15],*p1 = buf,*p2 = buf;
inline ll read(){
    #define num ch-'0'
    char ch;bool flag=0;ll res;
    while(!isdigit(ch=getc()))
    (ch=='-')&&(flag=true);
    for(res=num;isdigit(ch=getc());res=res*10ll+num);
    (flag)&&(res=-res);
    #undef num
    return res;
}
inline void write(ll x){
	if (x < 0) x = ~x + 1ll, putchar('-');
	if (x > 9) write(x / 10ll);
	putchar(x % 10ll + '0');
}
#define mid ((l + r)>>1)
#define ls (x<<1)
#define rs ((x<<1)|1)
#undef mid
#undef ls
#undef rs
#define maxn 101000
int a[maxn];
int b[maxn];
int n;
int check(int v)
{
	b[1] = v;
	rep(i,1,n-1)
	{
		b[i+1] = a[i] - b[i];
		if(b[i]<0)
		{
			if(i%2 == 1) return 1;
			else return -1;
		}
	}
	if(b[n]+b[1] < a[n]) return 1;
	else if(b[n]+b[1]>a[n]) return  -1;
	return 0;
}
void solve()
{
	n = read();
	rep(i,1,n) a[i] = read();
	int l = 0,r = a[1];
	int ans = 0;
	while(l<=r)
	{
		int mid = (l+r)>>1;
		int t = check(mid);
		if(t == 0) break;
		if(t == 1) l = mid+1;
		else r = mid - 1;
	}
	rep(i,1,n) cout<<b[i]*2<<" ";
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
	#endif
//	int T = read();
//	while(T--)
	solve();
}