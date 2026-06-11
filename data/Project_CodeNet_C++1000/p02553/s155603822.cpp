#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    
    ll ans= max(a*c,b*d);
    ans = max(ans, a*d);
    ans=max(ans,b*c);
    
    cout<<ans;
    
    return 0;
}