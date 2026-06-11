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
int n,m,t[N];
char s[N][N],S[N];

int main(){
	n=read();
	For(i,1,n) scanf("%s%d",s[i]+1,&t[i]);
	scanf("%s",S+1),m=strlen(S+1);
	For(i,1,n){
		bool flag=1;
		if (strlen(s[i]+1)!=m) continue;
		For(j,1,m) if (S[j]!=s[i][j]){flag=0;break;}
		if (flag){
			int ans=0;
			For(j,i+1,n) ans+=t[j];
			printf("%d\n",ans);
			break;
		}
	}
}