#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n,cnt=0; cin>>n;
    vector<P> a(n);
    rep(i,n){
        ll x,l;
        cin>>x>>l;
        a[i] = {x+l,x-l};
    }
    sort(all(a));
    ll mini=-INF;
    rep(i,n) {
        if(mini <= a[i].second){
            cnt++;
            mini = a[i].first;
        }
    }
    cout<<cnt<<endl;
    return 0;
}