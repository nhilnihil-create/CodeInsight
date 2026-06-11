#include <bits/stdc++.h>
using namespace std;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define int long long
#define fi first
#define se second

const int maxn=2e3+10;
int n;
pii a[maxn];
int f[maxn][maxn]; /// f[i][j]

main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    forinc(i,1,n){
        cin>>a[i].fi;a[i].se=i;
    }
    sort(a+1,a+n+1,greater<pii> ());
    forinc(i,1,n) forinc(j,0,i){
        int pos=a[i].se;
        int ty1=j;
        int ty2=min(n,n-(i-j)+1);
        if(j==0) f[i][j]=f[i-1][j]+a[i].fi*(ty2-pos);
        else if(j==i) f[i][j]=f[i-1][j-1]+ a[i].fi*(pos-ty1);
        else f[i][j]=max(f[i-1][j]+a[i].fi*(ty2-pos),f[i-1][j-1]+ a[i].fi*(pos-ty1));
    }
    int ret=0;
    forinc(i,0,n) ret=max(ret,f[n][i]);
    cout<<ret;
}
