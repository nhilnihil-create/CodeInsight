#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    return res;
}
int main(void){
    cin>>n;
    vector<ll> v,w;
    v=divisor(n);
    w=divisor(n-1);
    ll ans=w.size()-1;
    for(int i=1;i<v.size();i++){
        ll m=n;
        ll k=v[i];
        while(m%k==0){
            m=m/k;
        }
        if(m%k==1){
            ans++;
        }
    }
    cout<<ans<<endl;

}
