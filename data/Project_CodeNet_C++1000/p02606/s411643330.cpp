#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,r,d,ans=0;
    cin>>l>>r>>d;
    for(int i=1;i<=r;i++)
    {
        if(d*i>=l&&d*i<=r)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
