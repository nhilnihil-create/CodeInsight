#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int ans=0;
    int m=1;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        if(a==m)m++;
        else ans++;
    }

    if(m==1) cout<<-1<<"\n";
    else cout<<ans<<"\n";

    return 0;
}
