#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int x[110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>x[i];

    int ans=INF;
    for(int i=1;i<=100;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)sum+=(x[j]-i)*(x[j]-i);
        ans=min(ans,sum);
    }

    cout<<ans<<"\n";

    return 0;
}
