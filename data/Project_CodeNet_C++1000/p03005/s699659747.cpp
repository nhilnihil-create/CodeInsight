// This code wrote by chtholly_micromaker(MicroMaker)
#pragma GCC optimize("Ofast,O3,inline")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#define reg register
#define ALL(x) (x).begin(),(x).end()
#define mem(x,y) memset(x,y,sizeof x)
#define sz(x) (int)(x).size()
#define ln puts("")
#define lsp putchar(32)
#define pb push_back
#define MP make_pair
#define dbg(x) cerr<<">"<<__func__<<"\tLine: "<<__LINE__<<' '<<#x<<": "<<x<<endl
using namespace std;
template <class t> inline void read(t &s){s=0;
reg int f=1;reg char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();s*=f;return;}
template<class t,class ...A> inline void read(t &x,A &...a){read(x);read(a...);}
template <class t> inline void write(t x){if(x<0)putchar('-'),x=-x;
int buf[21],top=0;while(x)buf[++top]=x%10,x/=10;if(!top)buf[++top]=0;
while(top)putchar(buf[top--]^'0');return;}
inline void setIn(string s){freopen(s.c_str(),"r",stdin);return;}
inline void setOut(string s){freopen(s.c_str(),"w",stdout);return;}
inline void setIO(string s=""){setIn(s+".in");setOut(s+".out");return;}
template <class t>inline bool checkmin(t&x,t y){if(x>y){x=y;return 1;}return 0;}
template <class t>inline bool checkmax(t&x,t y){if(x<y){x=y;return 1;}return 0;}
inline int lowbit(int x){return x&(-x);}
signed main(void)
{
	int n,k;read(n,k);
	if(k==1)
	{
		puts("0");
		return 0;
	}
	write(n-k);
	return 0;
}

/*
 * Check List:
 * 1. Input / Output File (USACO and OI and UVa)
 * 2. long long 
 * 3. Special Test such as n=1
 * 4. Array Size
 * 5. Memory Limit (OI) int is 4 and longlong is 8
 * 6. Mod (a*b%p*c%p not a*b*c%p  ,  (a-b+p)%p not a-b )
 * 7. Name ( int k; for(int k...))
 * 8. more tests , (T=2 .. more)
 * 9. blank \n after a case
*/




