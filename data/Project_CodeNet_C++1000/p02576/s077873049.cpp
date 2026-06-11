#define inf 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define m_p  make_pair
#define ull unsigned long long
#define spd  ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ll n,x,t,ans;

    cin>>n>>x>>t;

    ans = n/x;

    if(n%x)ans++;

    cout<<ans*t<<endl;

}
