#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N=1e9+7;
int32_t main()
{
    IOS;
    int n,x,t;
    cin>>n>>x>>t;
    int ans = n%x==0?n/x:n/x+1;
    cout<<ans*t;
}