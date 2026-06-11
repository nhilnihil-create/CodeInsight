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
typedef std::vector<int> VI;
typedef std::pair<int,int> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

int main()
{
    char s[10];
    scanf("%s",s);
    int ans=0;
    if(s[0]=='R' || s[1]=='R' || s[2]=='R') ans=1;
    if(s[0]=='R' && s[1]=='R') ans=2;
    if(s[1]=='R' && s[2]=='R') ans=2;
    if(s[0]=='R' && s[1]=='R' && s[2]=='R') ans=3;
    cout<<ans;

    return 0;
}
