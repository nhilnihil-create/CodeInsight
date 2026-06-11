#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <string> a(n);
    vector <int> b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i]>>b[i];
    }
    string s;
    cin>>s;
    int ans=0;
    for(int i=(n-1);i>=0;i--)
    {
        if(a[i]==s)
        {
            cout<<ans;
            return 0;
        }
        else
        {
            ans+=b[i];
        }
    }
    return 0;
}
