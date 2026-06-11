#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(_i,_a,_n) for(int _i=_a;_i<=_n;++_i)
#define PER(_i,_a,_n) for(int _i=_n;_i>=_a;--_i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(_a) ({REP(_i,1,n) cout<<_a[_i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



#ifdef __APPLE__
const int N = 1e2+50;
#else
const int N = 1e6+50;
#endif


int n,a[N],b[N];
map<int,int> s;
int chk(int x, int y) {
	auto t = s;
	b[1] = x, b[2] = y;
	--t[x], --t[y];
	REP(i,3,n) {
		if (t[b[i-1]^b[i-2]]) {
			--t[b[i-1]^b[i-2]];
			b[i] = b[i-1]^b[i-2];
		}
		else return 0;
	}
	if (b[1]^b[n]^b[n-1]) return 0;
	if (b[2]^b[1]^b[n]) return 0;
	return 1;
}
int main() {
	scanf("%d", &n);
	REP(i,1,n) scanf("%d", a+i),++s[a[i]];
	if (s.size()<=3) {
		for (auto a:s) for (auto b:s) {
			if (chk(a.x,b.x)) return puts("Yes"),0;
		}
		puts("No");
	}
	else puts("No");
}







