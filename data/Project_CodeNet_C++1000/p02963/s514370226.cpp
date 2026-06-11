#include<bits/stdc++.h>
using namespace std;
#define rg register
#define rep(i,a,b) for (rg int i=(a);i<=(b);i++)
#define per(i,a,b) for (rg int i=(b);i>=(a);i--)
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
void solve()
{
	ll S = read();
	int res1,res2;
	res1 = res2 = (int)sqrt(S);
	while(S>1ll*res1*res2)
	{
		if(res1>res2) res2++;
		else res1++;
	}
	ll tmp = 1ll*res1*res2-S;
	for(ll i = 1;i<=sqrt(tmp);i++)
	{
		if(tmp%i==0)
		{
			if(i<=1e9 && (tmp/i) <= 1e9)
			{
				printf("0 0 %d %d %d %d",res1,i,tmp/i,res2);
				return;
			}
		}
	}
	printf("0 0 %d 0 0 %d",res1,res2);
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