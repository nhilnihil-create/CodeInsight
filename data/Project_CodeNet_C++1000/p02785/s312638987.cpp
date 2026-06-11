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
    ll n,k,cnt=0; cin>>n>>k;
    vector<ll> h(n);
    rep(i,n){
        cin>>h[i];
    }
    sort(h.rbegin(),h.rend());
    for(int i=k;i<n;i++){
        cnt+=h[i];
    }
    cout<<cnt<<endl;
    return 0;
}