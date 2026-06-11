#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b)
{
    return (a<b);
}
int main()
{
    int n,k,i,ans=0;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,com);
    for(i=0;i<k;i++)
        ans+=a[i];
    cout<<ans<<endl;
    return 0;
}