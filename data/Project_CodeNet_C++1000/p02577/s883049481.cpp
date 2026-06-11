#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define me0(a) memset(a,0,sizeof(a))
#define me1(a) memset(a,-1,sizeof(a))
#define op freopen("in.txt", "r", stdin)
#define op1 freopen("C:\\acm\\Cproj\\in.txt","r",stdin);
#define pr freopen("C:\\acm\\Cproj\\out.txt","w",stdout)
#define pr2 freopen("C:\\acm\\Cproj\\std.txt","w",stdout)
#define pii pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long LL;
template <class T>
void read(T &val) { T x = 0; T bz = 1; char c; for (c = getchar(); (c<'0' || c>'9') && c != '-'; c = getchar()); if (c == '-') { bz = -1; c = getchar(); }for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48; val = x * bz; }
const int maxn = 1e6 + 11;
const int mod=1e9+7;
int n,m,x,y,t;
char s[maxn];

int main(){
    scanf("%s",s);
    int len = strlen(s),ans = 0;
    fo(i,0,len-1) ans+=s[i]-'0';
    if(ans%9) puts("No");
    else puts("Yes");
    return 0;
}