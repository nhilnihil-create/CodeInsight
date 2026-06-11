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

const int N = 5e5+10;
int n,a[N];
char s[N];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1,j=1;i<=n;i=j){
		while (j<=n&&s[i]==s[j]) j++;
		if(s[i]=='<'){
			int l=0;
			a[i-1]=max(a[i-1],l);
			FOR(k,i,j) ++l,a[k]=max(a[k],l);
		} else if (s[i]=='>'){
			int l=-1;
			Dow(k,j-1,i) ++l,a[k]=max(a[k],l);
			++l,a[i-1]=max(a[i-1],l);
		}
	}
	ll ans=0;
	For(i,0,n) ans+=a[i];
	printf("%lld\n",ans);
}