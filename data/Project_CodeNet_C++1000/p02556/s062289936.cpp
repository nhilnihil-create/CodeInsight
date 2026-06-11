#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


/*
ll binpow(ll a, ll b) {
    ll res=1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}*/


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    ll n;
    cin>>n;
    vector<pair<ll,ll>>v;
    ll ans;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
        //sort(v.begin(),v.end());
        vector<ll>a,b;
        for(ll i=n-1;i>=0;i--)
        {
            a.push_back((v[i].first+v[i].second));
            b.push_back((v[i].first-v[i].second));
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ans=a[n-1]-a[0];
        ans=max(ans,(b[n-1]-b[0]));
    
    cout<<ans<<endl;
    
	return 0;
}