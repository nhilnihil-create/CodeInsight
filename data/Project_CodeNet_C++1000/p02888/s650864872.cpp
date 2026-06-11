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
#define maxn 2020
int a[maxn];
int n;
int erfen(int v,int l)
{
	int r = n,pre = l+1;l++;
	int ans = 0;
	while(l<=r)
	{
		int mid = (l+r)>>1;
		if(a[mid] <v)
		{
			ans = mid;
			l = mid+1;
		}
		else r = mid - 1;
	}
	if(ans == 0) return 0;
	return ans - pre+1;
}
void solve()
{
	n = read();
	rep(i,1,n) a[i] = read();
	sort(a+1,a+1+n);
	int ans = 0;
//	rep(i,1,n)
//	{
//		rep(j,i+1,n)
//		{
//			int cnt = erfen(a[i]+a[j],j);
//			ans+=cnt;
//		}
//	}
	rep(i,1,n-2)
	{
		rep(j,i+1,n-1)
		{
			int k = j+1;
			while(a[k]<a[i]+a[j]&&k<=n)
			{
				k++;
				ans++;
			}
		}
	}
	cout<<ans;
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