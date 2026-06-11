#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,ans=0,pos;cin>>n;long long ar[n];
    for(int i=0;i<n;i++){cin>>ar[i];}
    ///-----------------------------------///
    for(int i=0;i<n-1;i++)
    {
        if(ar[i]>ar[i+1])
        {
            ans+=ar[i]-ar[i+1];
            ar[i+1]=ar[i];
        }
    }
    ///-----------------------------------///
    cout<<ans<<endl;
}
