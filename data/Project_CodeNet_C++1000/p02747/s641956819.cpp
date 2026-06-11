#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int l=0;
    while(l<=(((int)s.size())-2) && s[l]=='h' && s[l+1]=='i')
    {
        l+=2;
    }
    if(l==s.size())
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}
