#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int cnt=0;
    int m=0;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        int h;
        cin>>h;

        if(m<h)
        {
            ans=max(ans,cnt);
            cnt=0;
        }
        else
        {
            cnt++;
        }
        m=h;
    }
    
    ans=max(ans,cnt);

    cout<<ans<<"\n";

    return 0;
}
