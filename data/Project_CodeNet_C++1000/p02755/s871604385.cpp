#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b;
    cin>>a>>b;

    int ans=0;

    for(int i=1;i<2000;i++)
    {
        if(i*8/100==a&&i*10/100==b)
        {
            ans=i;
            break;
        }
    }

    if(ans)cout<<ans<<"\n";
    else cout<<-1<<"\n";

    return 0;
}
