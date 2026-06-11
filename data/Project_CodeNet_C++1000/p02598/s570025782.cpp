#include <bits/stdc++.h>
using namespace std;
long a[200005],n,k;
bool check(int m)
{
    int sl=0;
    for(int i=1;i<=n;i++)
    {
        sl=sl+(a[i]/m);
        if(a[i]%m==0) sl--;
    }
    return (sl<=k);
}
int main()
{
    long dau=1,cuoi,giua,M;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cuoi=max(cuoi,a[i]);
    }
    while(dau<=cuoi)
    {
        giua=(dau+cuoi)/2;
        if(check(giua)==true)
        {
            M=giua;
            cuoi=giua-1;
        }
        else dau=giua+1;
    }
    cout<<M;
}
