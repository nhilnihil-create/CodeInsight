#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> v;
    rep(i,n){
        ll x,l;
        cin>>x>>l;
        v.push_back({x+l,x-l});
    }

    ll ans=0,s=-1LL<<60;
    sort(all(v));
    rep(i,n){
        if(s<=v[i].second){
            ans++;
            s=v[i].first;
        }
    }

    cout<<ans<<endl;
}
