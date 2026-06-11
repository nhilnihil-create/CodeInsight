#include <iostream>
#include <map>
#include <ctime>
#include <vector>
#include <climits>
#include <algorithm>
#include <random>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <bitset> 
#include <queue>
#define inf 0x3f3f3f3f
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, a, n) for(register int i = a; i <= n; ++ i)
#define per(i, a, n) for(register int i = n; i >= a; -- i)
#define ONLINE_JUDGE
using namespace std;
typedef long long ll;
const int mod=1e9+7;
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
    {
        write(x/10);
    }
    putchar(x%10+'0');
}
 
template<typename T> void read(T &x)
{
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;};
ll ksm(ll a,ll n){//看是否要mod 
	ll ans=1;
	while(n){
		if(n&1) ans=(ans*a)%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans%mod;
}
//==============================================================
const int maxn=1e5+10;
struct ti{
    ll x,y,c;
};
ti da[maxn];
ll a[maxn],b[maxn];
ll A,B,M;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	clock_t c1 = clock();
	//===========================================================
	read(A),read(B),read(M);
    ll ma=inf,mb=inf;
    rep(i,1,A){
        read(a[i]);
        ma=min(a[i],ma);
    }
    rep(i,1,B){
        read(b[i]);
        mb=min(b[i],mb);
    }
    ll ans=ma+mb;
    rep(i,1,M){
        int x,y,c;
        read(x),read(y),read(c);
        ans=min(ans,a[x]+b[y]-c);
    }
    write(ans);
	//===========================================================
	std::cerr << "Time:" << clock() - c1 << "ms" << std::endl;
	return 0;
}