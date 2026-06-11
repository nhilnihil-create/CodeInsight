#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin>>q;
    ll si=q;
    vector<pair<ll,ll>>v;
    while(q--){
    ll n,m;
    cin>>n>>m;
     v.push_back({n,m});
    }
    vector<ll>a,b;
    for(int i=0;i<si;i++)
    {
        a.push_back(v[i].first+v[i].second);
        b.push_back(v[i].first-v[i].second);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans = abs(a[si-1]-a[0]);
    ans=max(ans,b[si-1]-b[0]);
 cout<<ans;
}