#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#include<assert.h>
#include<chrono>
#include<random>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
template<typename T>inline void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T>inline void chkmax(T &x,T y){x=x>y?x:y;}
const int MAXN=100005;
vector<pii> ans;
int n;
int main()
{
	n=read();if(__builtin_popcount(n)==1)return puts("No"),0;
//	pr2(__builtin_ctz(n));
	puts("Yes");int k=1;for(;(k<<1)-1<=n;k<<=1);--k;
	for(int i=1;i<k;i++)ans.emplace_back(mp(i,i+1)),ans.emplace_back(mp(i+n,i+1+n));
	ans.emplace_back(mp(k,1+n));
	for(int i=k+1;i+1<=n;i+=2)
	{
		ans.emplace_back(mp(i,1+n));
		ans.emplace_back(mp(i+1,i));
		ans.emplace_back(mp(1+n,i+1+n));
		ans.emplace_back(mp(i+1+n,i+n));
	}
	if(!(n&1))
	{
		int ls=(1<<(__builtin_ctz(n)));
		int val=n^ls;
		if(val&1)ans.emplace_back(mp(val+n,n));
		else ans.emplace_back(mp(val,n));
		if(ls<=2)ans.emplace_back(mp(3,n+n));
		else ans.emplace_back(mp(ls+n,n+n));
	}
	for(auto p:ans)pr1(p.first),pr2(p.second);
	return 0;
}

