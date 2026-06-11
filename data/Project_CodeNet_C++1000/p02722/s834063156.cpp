#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<ll>divisor(ll n){
    vector<ll>res;
    for(ll i=1; i*i<=n; ++i){
        if(n%i==0){
            res.push_back(i);
            if(i*i!=n)res.push_back(n/i);
        }
    }
    return res;
}

int main(){
    ll n;
    cin>>n;
    vector<ll>x=divisor(n);
    int ans=0;
    rep(i,x.size()){
        if(x[i]==1)continue;
        ll m=n;
        while(m%x[i]==0){
            m/=x[i];
        }
        if(m%x[i]==1)ans++;
    }
    ans+=divisor(n-1).size()-1;
    cout<<ans<<endl;
}