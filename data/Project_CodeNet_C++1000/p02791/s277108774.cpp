#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mn=1e6,a,ans=0;cin>>n;
    while(n--)
    {
        cin>>a;mn=min(mn,a);
        if(a<=mn)ans++;
    }
    cout<<ans<<endl;
}
