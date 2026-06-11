#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(a) a.begin(),a.end()
#define int long long
const int MOD=1e9+7;
const int N=3e5+10;
int32_t main()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=10;i<=min(99LL,m);i++)
    {
        string s=to_string(i);
        if(s[0]-'0'>=2&&s[1]-'0'>=2)
        {
            if((s[0]-'0')*(s[1]-'0')<=n)
            {
                ans++;
                
            }
        }
    }
    cout<<ans<<endl;
}