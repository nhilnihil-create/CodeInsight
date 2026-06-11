#include<bits/stdc++.h>
using namespace std;
#define rg register
#define rep(i,a,b) for (rg int i=(a);i<=(b);i++)
#define per(i,a,b) for (rg int i=(b);i>=(a);i--)
#define pb push_back
#define lowbit(x) (x&(-x))
#define replow(i,a,b) for(rg int i = (a);i<=(b);i+=lowbit(i))
#define perlow(i,a,b) for(rg int i = (b);i>=(a);i-=lowbit(i))
#define mk make_pair
#define VI vector<int>
#define pii pair<int,int>
#define pLL pair<long long,long long>
#define fi first
#define se second
#define il inline
#define ll long long
#define ull unsigned long long
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
void solve()
{
	ll n = read();
	ll lim = (ll)sqrt(n * 1.0);
	per(i,1,lim)
	{
		if(n % i == 0)
		{
			cout<<(i+n/i-2);
			break;
		}
	}
}
int main()
{///
	#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
	#endif
//	int T = read();
//	while(T--)
	solve();
}