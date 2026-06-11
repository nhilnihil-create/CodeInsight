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

const int N = 2e5+10, mod = 1e9+7;
int n,a[N],b[N],cnt[2];
char s[N];

inline void GG(){
	puts("0");exit(0);
}

int main(){
	n=read(),scanf("%s",s+1),n=strlen(s+1);
	if (s[1]=='W') GG();
	a[1]=1;
	For(i,2,n) a[i]=(s[i]!=s[i-1]);
	b[1]=0;
	For(i,2,n){
		if (a[i]) b[i]=b[i-1];
			else b[i]=b[i-1]^1;
	}
	For(i,1,n) cnt[b[i]]++;
	if (cnt[0]!=n/2) GG();
	int tot=0,ans=1;
	Dow(i,n,1){
		if (b[i]==1) ++tot;
			else ans=1ll*ans*tot%mod,--tot;
	}
	For(i,1,n/2) ans=1ll*ans*i%mod;
	printf("%d\n",ans);
}