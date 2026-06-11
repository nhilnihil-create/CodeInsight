#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<ll,ll>;
using v  = vector<ll>;
using vv = vector<v>;
const int MOD = 1000000007;

int main(){
    int n;
    ll d,a;
    cin >>n>>d>>a;
    
    vector<P> xh(n);
    rep(i,n){
        cin >>xh[i].first>>xh[i].second;
        xh[i].second = (xh[i].second+a-1)/a;
    }
    
    sort(xh.begin(),xh.end());
    
    v x,h;
    rep(i,n){
        x.push_back(xh[i].first);
        h.push_back(xh[i].second);
    }
    
    v f(n,0);
    ll ans = 0;
    
    rep(i,n){
        if(i)f[i]+=f[i-1];
        
        h[i] -= f[i];
        if(h[i]<=0)continue;
        
        ll ran = x[i]+2LL*d;
        
        auto itr = upper_bound(x.begin(), x.end(), ran)-x.begin();
        if(itr<n)f[itr] -= h[i];
        
        ans += h[i];
        
        f[i] += h[i];
        //cout << f[i] <<" "<< ans << endl;
    }
    
    cout << ans << endl;
    
    return 0;
}