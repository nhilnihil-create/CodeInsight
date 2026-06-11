#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> a,b;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        a.push_back(x+y);
        b.push_back((x-y));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll maxip = (a[n-1] - a[0]);
    ll maixn = (b[n-1] - b[0]) ;
    ll ans = max(maxip,maixn);
    cout<<ans;
    return 0;
}