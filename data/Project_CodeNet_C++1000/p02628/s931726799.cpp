#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,k;
    cin>>n>>k;
    vector <ll>  ans(0);
    ll x;
    for(ll i=1;i<=n;i++)    cin>>x,ans.push_back(x);
    sort(ans.begin(),ans.end());
    ll now=0;
    for(ll i=0;i<k;i++) now+=ans[i];
    cout<<now;
    return 0;
}
