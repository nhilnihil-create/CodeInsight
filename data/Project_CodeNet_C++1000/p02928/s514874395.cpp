#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 2010, mod = 1e9+7;
int n,k,a[N];

inline int calc(int n){
	return 1ll*(n+1)*n/2%mod;
}

int main(){
	n=read(),k=read();
	For(i,1,n) a[i]=read();
	int ans=0;
	For(i,1,n){
		FOR(j,1,i) if (a[i]>a[j]) ans=(ans+calc(k-1))%mod;
		For(j,i+1,n) if (a[i]>a[j]) ans=(ans+calc(k))%mod;
	}
	printf("%d\n",ans);
}