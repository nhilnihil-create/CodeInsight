#include<bits/stdc++.h>
using  namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int t=n/i;
        if(n%i==0 ) t--;
        ans+=t;
    }
    cout<<ans<<endl;
    return 0;
}
