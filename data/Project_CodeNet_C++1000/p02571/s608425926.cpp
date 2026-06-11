#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod=1e9+7;
const int N=1e6+10;
void read(int &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0') if(ch=='-') d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
void read(ll &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0') if(ch=='-') d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
char s[N],t[N];
int main()
{
    scanf("%s %s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    int ans=0x3fffffff;
    for(int i=1;i+m-1<=n;i++)
    {
        int k=i,now=0;
        for(int j=1;j<=m;j++)
        {
            //cout<<s[k]<<" "<<s[j]<<endl;
            if(s[k]!=t[j]) now++;
            k++;
        }
        ans=min(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}
