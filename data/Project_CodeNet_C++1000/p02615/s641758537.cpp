#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> V;
bool cmp(ll A,ll B){
    return A>B;
}
int main() {
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        V.push_back(x);
    }
    sort(V.begin(),V.end(),cmp);
    n-=2;
    ll ans=V[0];
    ll have=n/2,rest=n%2;
    for(ll i=1;i<=have;i++){
        ans+=V[i]*2;
    }
    if(rest){
        ans+=V[have+1];
    }
    cout<<ans;
    return 0;
}
