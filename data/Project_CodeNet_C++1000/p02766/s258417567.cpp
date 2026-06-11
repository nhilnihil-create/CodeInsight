#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,r;
    cin>>n>>r;
    lli ans=0;
    while(n>0)
    {
        n=n/r;
        ans++;
    }
    cout<<ans<<"\n";
}