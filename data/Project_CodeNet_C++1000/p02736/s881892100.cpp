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

const int N = 1e6+10;
int n,cnt[3];
char s[N];

inline int C(int n,int m){
	if (n<m) return 0;
	if (n<=1) return 1; 
	return C(n/2,m/2)*C(n%2,m%2)%2;
}

int main(){
	n=read()-1,scanf("%s",s+1);
	For(i,1,n) s[i]=abs(s[i]-s[i+1]);
	if (n==1) return printf("%d\n",s[1]),0; 
	For(i,1,n) cnt[s[i]]++;
	if (cnt[1]==0){
		int ans=0;
		For(i,1,n) if (s[i]) ans=(ans+C(n-1,i-1))%2;
		printf("%d\n",ans==1?2:0);
	} else {
		int ans=0;
		For(i,1,n) if (s[i]==1) ans=(ans+C(n-1,i-1))%2;
		printf("%d\n",ans);
	}
}