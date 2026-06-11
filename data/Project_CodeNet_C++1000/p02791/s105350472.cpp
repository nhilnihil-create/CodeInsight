#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,ans=1,mn;
    cin>>n;
    cin>>mn;
    for(int i=1;i<n;i++)
    {
        cin>>x;
        if(x<=mn)
            {
                ++ans;
                mn = x;
            }
    }
    cout<<ans;
    return 0;
}

