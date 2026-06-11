#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,k,q,all=0;
    cin>>n>>k>>q;
    vector<ll> p(n,k-q);
    rep(i,q){
        ll a; cin>>a;
        p[a-1]++;
    }
    rep(i,n){
        if(p[i]>0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}