#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    n--;
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        ans+=n/i;
    }
    cout<<ans<<endl;
    return 0;
}
