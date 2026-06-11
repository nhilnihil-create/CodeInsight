#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#include <cstdio>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<LL,LL> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

const int maxn=2e5+5;
char s[maxn];
int l,r;

int main()
{
    int n=read();
    scanf("%s",s+1);
    l=1,r=n;
    int ans=0;
    while(l<=r)
    {
        while(l<=n && s[l]=='R') l++;
        while(r>=1 && s[r]=='W') r--;
        if(l<r) swap(s[l],s[r]),ans++;
    }
    cout<<ans;

    return 0;
}
