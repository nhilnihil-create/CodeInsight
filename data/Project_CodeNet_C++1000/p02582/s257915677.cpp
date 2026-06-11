#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int ans=0;
    for(int i=0;i<(int)s.size();i++)
    {
        int cnt=0;
        while(i<(int)s.size()&&s[i]=='R')
        {
            i++;
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
