#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n-1);
    for(auto &i:a)
        cin>>i;
    for(auto &i:b)
        cin>>i;
    for(auto &i:c)
        cin>>i;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            ans+=b[a[i]-1];
        }
        else
        {
            if(a[i]-a[i-1]==1)
            {
                ans+=b[a[i]-1];
                ans+=c[a[i-1]-1];
            }
            else
                ans+=b[a[i]-1];
        }
    }
    cout<<ans;
    return 0;
}
//17:05
//13+5+8+24