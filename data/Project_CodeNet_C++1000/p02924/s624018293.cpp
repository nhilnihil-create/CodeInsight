#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll ans=(n*(n+1))/2;
    ans-=n;
    cout<<ans<<endl;
}
