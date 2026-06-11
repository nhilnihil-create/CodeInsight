#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans = max(max(max(a*c,a*d),b*c),b*d);
    cout<<ans;  
    return 0;
}
