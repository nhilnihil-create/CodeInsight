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

const int N = 110;
int n,k;
ll ans;
char s[N];

int main(){
	scanf("%s%d",s+1,&k),n=strlen(s+1);
	bool flag=1;
	For(i,2,n) flag&=s[i]==s[1];
	if (flag) return printf("%lld\n",1ll*n*k/2),0;
	int x=0,y=0;
	for (int l=1,r=1;l<=n;l=++r){
		while (r<n&&s[r+1]==s[l]) ++r;
		if (l==1) x=r-l+1;
		if (r==n) y=r-l+1;
		ans+=1ll*((r-l+1)/2)*k;
	}
	if (s[1]==s[n]&&(x&1)&&(y&1)) ans+=k-1;
	printf("%lld\n",ans);
}