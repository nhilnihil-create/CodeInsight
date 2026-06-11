#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> v(N);
    rep(i,N) cin>>v[i];
    vector<ll> a(N);
    rep(i,N){
        if(i==0) a[i] = v[i]%K;
        else a[i] = (a[i-1]+v[i])%K;
    }
    rep(i,N) {
        a[i] = (a[i]-i-1)%K;
        if(a[i]<0) a[i]+=K;
    }
    map<ll,vector<ll>> m;
    m[0].push_back(0);
    rep(i,N) m[a[i]].push_back(i+1);
    ll ans = 0;
    for(auto x:m){
        int l = x.second.size();
        rep(i,l){
            auto ite = lower_bound(x.second.begin(),x.second.end(),x.second[i]+K);
            ans += (ite-x.second.begin())-i-1;
        }
    }
    cout<<ans<<endl;
}