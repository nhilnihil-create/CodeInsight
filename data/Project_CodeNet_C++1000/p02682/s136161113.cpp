#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,k,ans=0;
    cin>>a>>b>>c>>k;
    if(a<=k)
    {
        ans=a;
        k-=a;
    }
    else
    {
        ans=k;
        k=0;
    }
    if(b<=k)
        k-=b;
    else
        k=0;
    cout<<ans-k<<endl;
}
