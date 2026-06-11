#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='?')
        {
            s[i]='D';
        }
    }
    cout<<s;
    return 0;
}
