#include <bits/stdc++.h>
using namespace std;

main()
{
    int n; cin>>n;
    string s; cin>>s;
    string clst="RGB";
    vector acc(3,vector<int>(n+1));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            acc[j][i+1]=acc[j][i]+(s[i]==clst[j]);
        }
    }
    long long ans=0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            if(s[i]==s[j])
            {
                continue;
            }
            int ci=clst.find(s[i]);
            int cj=clst.find(s[j]);
            int cmid=3-ci-cj;
            ans+=acc[cmid][i]-acc[cmid][j];
            if((i+j)&1) continue;
            ans-=(s[(i+j)/2]==clst[cmid]);
        }
    }
    cout << ans << "\n";
}