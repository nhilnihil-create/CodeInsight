/*
很神奇的题
首先可以想到同时减1，范围变为{0,1,2}
分类讨论
只有0和1，算1对答案的贡献
只有0和2，同除以2，化为0和1，最后答案乘以2
只有1和2，同减1，化为0和1
都有，2变为0，化为0和1
*/


#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e6+5;
char s[maxn];
int a[maxn],f[maxn],c0,c1,c2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>s+1;
    for(int i=1;i<=n;i++)
    {
        a[i]=s[i]-'1';
        if(a[i]==0) c0=1;
        if(a[i]==1) c1=1;
        if(a[i]==2) c2=1;
    }
    for(int i=2;i<=n;i++)
    {
        f[i] = f[i-1];
        int ii=i;
        while(!(ii&1)) {f[i]++;ii>>=1;}
    }
    int t=1,ans=0;
    if(c0 && c1 && c2)
    {
        for(int i=1;i<=n;i++) a[i]=a[i]==2?0:a[i];
    }
    else if(c0 && c2) t=2;
    else if(c1 && c2)
    {
        for(int i=1;i<=n;i++) a[i]--;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]) ans += (f[n-1]-f[i-1]-f[n-i]==0);
    }
    ans %= 2;
    cout<<ans*t<<endl;
    return 0;
}
