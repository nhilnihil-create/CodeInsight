#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define endl "\n"



int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans = max(a,b)*max(c,d);
    ans = max(ans,min(a,b)*min(c,d));
    ans = max(ans,max(a,b)*min(c,d));
    ans = max(ans,min(a,b)*max(c,d));
    cout<<ans<<endl;
}
