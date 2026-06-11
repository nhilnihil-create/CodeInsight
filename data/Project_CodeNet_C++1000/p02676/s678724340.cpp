
/*

 Remember, Hope is a good thing... May be the best of things... And No Good thing ever Dies !!!

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007
const ll inf=(1LL<<60)-1;
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
void solve()
{
    ll k;
    string s,s1;
    s1="...";
    cin>>k>>s;
    if(s.size()>k)
    {
        for(int i=0;i<k;i++)
            cout<<s[i];
        cout<<s1;
    }
    else
        cout<<s<<endl;

}
int main()
{
    IOS;
    // ll t;
    //cin>>t;
    //while(t--)
    solve();
    return 0;
}
