#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,ans = 0;
    cin>>n;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(i % 15 == 0||i % 5 == 0 || i % 3 == 0)continue;
        ans += i;
    }
    cout<<ans<<endl;
}
int main()
{

    //int t;
   // cin>>t;
   // while(t--)
        solve();
    return 0;
}

