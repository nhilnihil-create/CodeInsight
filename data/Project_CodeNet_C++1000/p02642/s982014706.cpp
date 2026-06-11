#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>cnt;
const int nax = 1e6 + 44;

int divs[nax];

main()
{
    int n;
    cin>>n;
    int a[n+5],ans=0;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1; i<nax; i++)
    {
        for(int j=i; j<nax; j+=i)
        {
            divs[j]+=cnt[i];
        }
    }
    for(int i=1; i<nax; i++)
    {
        if(cnt[i]&&divs[i]==1)
        {
            ans+=cnt[i];
        }
    }
    cout<<ans<<endl;

}

