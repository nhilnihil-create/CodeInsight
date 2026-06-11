
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
    string s;
    cin>>s;
    if(s[s.size()-1]=='0' || s[s.size()-1]=='1' || s[s.size()-1]=='6' || s[s.size()-1]=='8')
        cout<<"pon"<<endl;
    else if(s[s.size()-1]=='3')
        cout<<"bon"<<endl;
    else
        cout<<"hon"<<endl;
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
