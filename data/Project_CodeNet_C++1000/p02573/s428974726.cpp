#include <iostream>
#include <cstring>
using namespace std;
int n,m,x,y,f[210000],cnt[210000];
int find(int k)
{
    if(f[k]==k)return k;
    return f[k]=find(f[k]);
}
int main(void)
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        f[find(x)]=find(y);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int fi=find(i);
        cnt[fi]++;
        ans=max(cnt[fi],ans);
    }
    cout<<ans<<endl;
    return 0;
}
