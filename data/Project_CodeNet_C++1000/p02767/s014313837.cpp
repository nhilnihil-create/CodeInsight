#include <iostream>

using namespace std;
int ans,s,x[101],n,i,j,mn,mx;
int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
    {
    cin >> x[i];
    mn=min(mn,x[i]);
    mx=max(x[i],mx);
    }
    
    for (i=mn; i<=mx; i++)
    {
        for (j=1; j<=n; j++)
        s+=(max(i,x[j])-min(i,x[j]))*(max(i,x[j])-min(i,x[j]));
        if (i==mn) ans=s;
        else
        ans=min(ans,s);
        s=0;
    }
    cout<<ans<<endl;
    
    
}
