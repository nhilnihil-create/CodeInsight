#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


void solve()
{
    int n;cin>>n;string s;cin>>s;
    string ans="";
    for(char c:s)
    {
        int d=c-'A';
        d+=n;
        d=d%26;
        // if(d==0)
        // d=26;
        ans+=(char)('A'+d);
        
    }
    cout<<ans<<endl;
    
}
int32_t main()
{
    rapido;
    int t;
    //cin>>t;
      t=1;
    while(t--)
    solve();
}


//NOPQRSTUVWXYZABCDEFGHIJKLM
//NOPQRSTUVWXYZZBCDEFGHIJKLM